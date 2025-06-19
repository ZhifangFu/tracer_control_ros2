#include <string>
#include <memory>
#include <thread>
#include <chrono>
#include <functional>

#include <rclcpp/rclcpp.hpp>
#include "tracer_base/tracer_messenger.hpp"

using namespace westonrobot;

int main(int argc, char **argv)
{
    // setup ROS2 node
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("tracer_base");
    
    RCLCPP_INFO(node->get_logger(), "Starting tracer_base_node...");
    
    // create robot object
    auto robot = std::make_shared<TracerRobot>();
    if (!robot) {
        RCLCPP_FATAL(node->get_logger(), "Failed to create robot object");
        return -1;
    }
    RCLCPP_INFO(node->get_logger(), "Robot object created at %p", robot.get());

    // create messenger object
    auto messenger = std::make_shared<TracerROSMessenger>(robot, node);
    RCLCPP_INFO(node->get_logger(), "Messenger object created at %p", messenger.get());
    
    // ensure messenger is valid
    if (!messenger->IsValid()) {
        RCLCPP_FATAL(node->get_logger(), "Messenger object is not valid");
        rclcpp::shutdown();
        return -1;
    }

    // fetch parameters
    messenger->odom_frame_ = node->declare_parameter("odom_frame", std::string("odom"));
    messenger->base_frame_ = node->declare_parameter("base_frame", std::string("base_link"));
    messenger->simulated_robot_ = node->declare_parameter("simulated_robot", false);
    std::string port_name = node->declare_parameter("port_name", std::string("can2"));
    messenger->port_name_ = port_name;  // store port name for reconnection

    RCLCPP_INFO(node->get_logger(), "Parameters:");
    RCLCPP_INFO(node->get_logger(), "  port_name = %s", port_name.c_str());
    RCLCPP_INFO(node->get_logger(), "  odom_frame = %s", messenger->odom_frame_.c_str());
    RCLCPP_INFO(node->get_logger(), "  base_frame = %s", messenger->base_frame_.c_str());
    RCLCPP_INFO(node->get_logger(), "  simulated_robot = %s", 
                messenger->simulated_robot_ ? "true" : "false");

    // connect to robot (if not simulated)
    if (!messenger->simulated_robot_) {
        RCLCPP_INFO(node->get_logger(), "Attempting to connect to port: %s", port_name.c_str());
        if (port_name.find("can") != std::string::npos) {
            try {
                // Step 1: 初始连接
                robot->Connect(port_name);
                RCLCPP_INFO(node->get_logger(), "SocketCAN connection established");
                
                // 等待硬件初始化
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                
                // Step 2: 启用指令模式
                robot->EnableCommandedMode();
                RCLCPP_INFO(node->get_logger(), "Commanded mode enabled");
                
                // 等待命令模式生效
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
                
                // 验证连接
                for (int i = 0; i < 3; i++) {
                    try {
                        auto state = robot->GetRobotState();
                        RCLCPP_INFO(node->get_logger(), "Initial state %d: battery=%.1fV, mode=%d, state=%d, error=%d",
                                   i+1, 
                                   state.system_state.battery_voltage * 0.1,
                                   state.system_state.control_mode,
                                   state.system_state.vehicle_state,
                                   state.system_state.error_code);
                        
                        if (state.system_state.battery_voltage > 10.0) {
                            RCLCPP_INFO(node->get_logger(), "Connection verified with valid voltage");
                            messenger->is_connected_ = true;
                            break;
                        }
                    } catch (...) {
                        RCLCPP_WARN(node->get_logger(), "State reading attempt %d failed", i+1);
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }
                
                if (!messenger->is_connected_) {
                    RCLCPP_WARN(node->get_logger(), "Continuing despite state read issues");
                    messenger->is_connected_ = true;  // 强制设置连接状态
                }
            } 
            catch (const std::system_error& e) {
                RCLCPP_FATAL(node->get_logger(), "System error (code %d): %s", 
                            e.code().value(), e.what());
                rclcpp::shutdown();
                return -1;
            }
            catch (const std::exception& e) {
                RCLCPP_FATAL(node->get_logger(), "Exception: %s", e.what());
                rclcpp::shutdown();
                return -1;
            } 
            catch (...) {
                RCLCPP_FATAL(node->get_logger(), "Unknown error occurred while connecting");
                rclcpp::shutdown();
                return -1;
            }
        } else {
            RCLCPP_INFO(node->get_logger(), "Using UART to talk with the robot");
        }
    } else {
        RCLCPP_INFO(node->get_logger(), "Running in simulated robot mode");
        messenger->is_connected_ = true;
    }

    // setup subscription
    RCLCPP_INFO(node->get_logger(), "Setting up subscriptions");
    messenger->SetupSubscription();
    RCLCPP_INFO(node->get_logger(), "Subscriptions set up successfully");

    // 初始化完成延迟
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // main loop
    RCLCPP_INFO(node->get_logger(), "Starting main loop at 20Hz");
    rclcpp::Rate rate_20hz(20);
    int state_fail_count = 0;
    const int max_state_fail = 10;
    
    while (rclcpp::ok()) {
        try {
            if (messenger->simulated_robot_) {
                double linear, angular;
                messenger->GetCurrentMotionCmdForSim(linear, angular);
                messenger->PublishSimStateToROS(linear, angular);
            } else {
                if (messenger->is_connected_) {
                    bool state_ok = messenger->PublishStateToROS();
                    if (!state_ok) {
                        state_fail_count++;
                        if (state_fail_count >= max_state_fail) {
                            RCLCPP_WARN(node->get_logger(), "Too many state failures, marking as disconnected");
                            messenger->is_connected_ = false;
                        }
                    } else {
                        state_fail_count = 0;
                    }
                } else {
                    // 尝试重新连接
                    if (messenger->AttemptReconnection(port_name)) {
                        state_fail_count = 0;
                        RCLCPP_INFO(node->get_logger(), "Reconnected successfully");
                    } else {
                        RCLCPP_WARN(node->get_logger(), "Reconnection attempt failed");
                    }
                }
            }
        } catch (const std::exception& e) {
            RCLCPP_ERROR(node->get_logger(), "Exception in main loop: %s", e.what());
            messenger->is_connected_ = false;
        } catch (...) {
            RCLCPP_ERROR(node->get_logger(), "Unknown exception in main loop");
            messenger->is_connected_ = false;
        }
        
        rclcpp::spin_some(node);
        rate_20hz.sleep();
    }
    
    RCLCPP_INFO(node->get_logger(), "Shutting down");
    
    // 安全断开

    
    rclcpp::shutdown();
    return 0;
}