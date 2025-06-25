#include "tracer_base/tracer_messenger.hpp"
#include <cmath>
#include <algorithm>
#include <tf2/LinearMath/Quaternion.h>
#include <chrono>

using namespace std::chrono_literals;

namespace westonrobot
{

TracerROSMessenger::TracerROSMessenger(std::shared_ptr<TracerRobot> tracer, rclcpp::Node::SharedPtr nh) 
    : tracer_(tracer), nh_(nh)
{
    // Initialize TF broadcaster
    tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(nh_);
    
    // Initialize time
    last_time_ = nh_->now();
    current_time_ = nh_->now();
    
    RCLCPP_DEBUG(nh_->get_logger(), "TracerROSMessenger initialized");
}

void TracerROSMessenger::SetupSubscription()
{
    // Validate before proceeding
    if (!IsValid()) {
        RCLCPP_ERROR(nh_->get_logger(), "Cannot setup subscriptions - messenger not valid");
        return;
    }
    
    // Create publishers
    odom_publisher_ = nh_->create_publisher<nav_msgs::msg::Odometry>(odom_frame_, 50);
    status_publisher_ = nh_->create_publisher<tracer_msgs::msg::TracerStatus>("/tracer_status", 10);

    // Create motion command subscriber
    motion_cmd_subscriber_ = nh_->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel", 5, 
        [this](const geometry_msgs::msg::Twist::SharedPtr msg) {
            try {
                if (!is_connected_ || !tracer_) {
                    RCLCPP_WARN_THROTTLE(nh_->get_logger(), *nh_->get_clock(), 2000, 
                                       "Tracer not available, ignoring twist command");
                    return;
                }
                TwistCmdCallback(msg);
            } catch (const std::exception& e) {
                RCLCPP_ERROR(nh_->get_logger(), "Exception in TwistCmdCallback: %s", e.what());
            } catch (...) {
                RCLCPP_ERROR(nh_->get_logger(), "Unknown exception in TwistCmdCallback");
            }
        }
    );
    
    // Create light command subscriber
    light_cmd_subscriber_ = nh_->create_subscription<tracer_msgs::msg::TracerLightCmd>(
        "/tracer_light_control", 5, 
        [this](const tracer_msgs::msg::TracerLightCmd::SharedPtr msg) {
            try {
                if (!is_connected_ || !tracer_) {
                    RCLCPP_WARN_THROTTLE(nh_->get_logger(), *nh_->get_clock(), 2000, 
                                       "Tracer not available, ignoring light command");
                    return;
                }
                LightCmdCallback(msg);
            } catch (const std::exception& e) {
                RCLCPP_ERROR(nh_->get_logger(), "Exception in LightCmdCallback: %s", e.what());
            } catch (...) {
                RCLCPP_ERROR(nh_->get_logger(), "Unknown exception in LightCmdCallback");
            }
        }
    );
    
    RCLCPP_INFO(nh_->get_logger(), "Subscriptions set up successfully");
}

void TracerROSMessenger::TwistCmdCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    // For simulated robot, just store the command
    if (simulated_robot_) {
        std::lock_guard<std::mutex> guard(twist_mutex_);
        current_twist_ = *msg;
        return;
    }
    
    // For real robot, send the command
    try {
        // Add safety limits with explicit casting
        double safe_linear = std::min(std::max(msg->linear.x, -2.0), 2.0);
        double safe_angular = std::min(std::max(msg->angular.z, -1.57), 1.57);
        
        tracer_->SetMotionCommand(safe_linear, safe_angular);
        RCLCPP_DEBUG(nh_->get_logger(), "Sent motion command: linear=%.2f, angular=%.2f", 
                    safe_linear, safe_angular);
    } 
    catch (const std::exception& e) {
        RCLCPP_ERROR(nh_->get_logger(), "Failed to send motion command: %s", e.what());
        is_connected_ = false;
    }
}

void TracerROSMessenger::GetCurrentMotionCmdForSim(double &linear, double &angular)
{
    std::lock_guard<std::mutex> guard(twist_mutex_);
    linear = current_twist_.linear.x;
    angular = current_twist_.angular.z;
}

void TracerROSMessenger::LightCmdCallback(const tracer_msgs::msg::TracerLightCmd::SharedPtr msg)
{
    // For simulated robot, just log
    if (simulated_robot_) {
        RCLCPP_INFO(nh_->get_logger(), "Simulated robot received light command");
        return;
    }
    
    // For real robot, send the light command
    try {
        LightCommandMessage cmd;
        cmd.front_light.mode = static_cast<AgxLightMode>(msg->front_mode);
        cmd.front_light.custom_value = msg->front_custom_value;
        
        tracer_->SetLightCommand(cmd.front_light.mode, cmd.front_light.custom_value);
        RCLCPP_DEBUG(nh_->get_logger(), "Set light mode: %d, value: %d", 
                    static_cast<int>(cmd.front_light.mode), cmd.front_light.custom_value);
    } 
    catch (const std::exception& e) {
        RCLCPP_ERROR(nh_->get_logger(), "Failed to set light command: %s", e.what());
        is_connected_ = false;
    }
}

bool TracerROSMessenger::PublishStateToROS()
{
    // Check connection status
    if (!is_connected_) {
        RCLCPP_WARN_THROTTLE(nh_->get_logger(), *nh_->get_clock(), 5000, 
                           "Tracer not connected, skipping publish");
        return false;
    }
    
    // Check pointer validity
    if (!tracer_) {
        RCLCPP_ERROR(nh_->get_logger(), "Tracer pointer is null in PublishStateToROS");
        return false;
    }
    
    current_time_ = nh_->now();
    
    // First publish special handling
    if (first_publish_) {
        last_time_ = current_time_;
        first_publish_ = false;
        RCLCPP_DEBUG(nh_->get_logger(), "First publish, skipping data");
        return true;
    }
    
    // Calculate time delta
    double dt = (current_time_ - last_time_).seconds();
    
    // Check time delta validity
    if (dt <= 0.0 || dt > 1.0) {
        RCLCPP_WARN(nh_->get_logger(), "Invalid delta time: %.6f seconds, using safe value", dt);
        dt = 0.05;  // Use safe value of 50ms
    }

    bool publish_success = false;
    
    try {
        // Lock to protect state access
        std::lock_guard<std::mutex> lock(state_mutex_);
        
        // Get robot state
        auto robot_state = tracer_->GetRobotState();
        
        // Validate battery voltage
        if (robot_state.system_state.battery_voltage < 10.0 || 
            robot_state.system_state.battery_voltage > 300.0) {
            RCLCPP_WARN_THROTTLE(nh_->get_logger(), *nh_->get_clock(), 5000,
                               "Suspicious battery voltage: %.1fV, skipping publish", 
                               robot_state.system_state.battery_voltage * 0.1);
            return false;
        }
        
        // Get actuator state
        auto actuator_state = tracer_->GetActuatorState();

        // Create status message
        auto status_msg = std::make_unique<tracer_msgs::msg::TracerStatus>();
        status_msg->header.stamp = current_time_;
        
        // Fill message
        status_msg->linear_velocity = robot_state.motion_state.linear_velocity;
        status_msg->angular_velocity = robot_state.motion_state.angular_velocity;
        
        status_msg->base_state = robot_state.system_state.vehicle_state;
        status_msg->control_mode = robot_state.system_state.control_mode;
        status_msg->fault_code = robot_state.system_state.error_code;
        status_msg->battery_voltage = robot_state.system_state.battery_voltage * 0.1;
        
        // Motor states are fixed size array (no resize needed)
        for (int i = 0; i < 2; ++i) {
            status_msg->motor_states[i].rpm = actuator_state.actuator_hs_state[i].rpm;
        }
        
        // Fill light state
        status_msg->light_control_enabled = robot_state.light_state.enable_cmd_ctrl;
        status_msg->front_light_state.mode = robot_state.light_state.front_light.mode;
        status_msg->front_light_state.custom_value = robot_state.light_state.front_light.custom_value;
        
        // Publish status
        status_publisher_->publish(std::move(status_msg));
        
        // Safe value limiting - manual clamping
        float safe_linear = std::min(std::max(robot_state.motion_state.linear_velocity, -5.0f), 5.0f);
        float safe_angular = std::min(std::max(robot_state.motion_state.angular_velocity, -3.14f), 3.14f);
        
        // Publish odometry
        PublishOdometryToROS(static_cast<double>(safe_linear), 
                            static_cast<double>(safe_angular), 
                            dt);
        publish_success = true;
        
        RCLCPP_DEBUG(nh_->get_logger(), "Published state successfully");
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(nh_->get_logger(), "Error in PublishStateToROS: %s", e.what());
        is_connected_ = false;
    } catch (...) {
        RCLCPP_ERROR(nh_->get_logger(), "Unknown error in PublishStateToROS");
        is_connected_ = false;
    }
    
    // Update time
    last_time_ = current_time_;
    return publish_success;
}

void TracerROSMessenger::PublishSimStateToROS(double linear, double angular)
{
    // Publish state for simulated robot
    current_time_ = nh_->now();
    double dt = 1.0 / sim_control_rate_;
    
    // Create and publish status message
    auto status_msg = std::make_unique<tracer_msgs::msg::TracerStatus>();
    status_msg->header.stamp = current_time_;
    
    // Fill with simulated data
    status_msg->linear_velocity = linear;
    status_msg->angular_velocity = angular;
    status_msg->base_state = 0x00;      // Normal state
    status_msg->control_mode = 0x01;    // Motion control mode
    status_msg->fault_code = 0x00;      // No error
    status_msg->battery_voltage = 29.5; // Simulated battery
    status_msg->light_control_enabled = false;
    
    status_publisher_->publish(std::move(status_msg));
    
    // Publish odometry
    PublishOdometryToROS(linear, angular, dt);
}

bool TracerROSMessenger::AttemptReconnection(const std::string& port_name)
{
    if (!tracer_) {
        RCLCPP_ERROR(nh_->get_logger(), "AttemptReconnection: tracer_ is null");
        return false;
    }
    
    try {
        RCLCPP_INFO(nh_->get_logger(), "Attempting to reconnect to port: %s", port_name.c_str());
        
        // Skip Disconnect() as it may not be available
        RCLCPP_WARN(nh_->get_logger(), "Skipping Disconnect() - method not available");
        
        // 安全延迟
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        // 重新连接
        tracer_->Connect(port_name);
        RCLCPP_INFO(nh_->get_logger(), "Reconnection established");
        
        // 启用指令模式
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        tracer_->EnableCommandedMode();
        RCLCPP_INFO(nh_->get_logger(), "Commanded mode enabled");
        
        // 验证连接
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        
        try {
            auto state = tracer_->GetRobotState();
            RCLCPP_INFO(nh_->get_logger(), "Battery after reconnect: %.1fV", 
                      state.system_state.battery_voltage * 0.1);
            
            // 设置连接状态
            if (state.system_state.battery_voltage > 10.0) {
                is_connected_ = true;
                return true;
            }
        } catch (...) {
            RCLCPP_WARN(nh_->get_logger(), "Failed to read state after reconnect, assuming connected");
            is_connected_ = true;
            return true;
        }
    } 
    catch (const std::exception& e) {
        RCLCPP_ERROR(nh_->get_logger(), "Reconnection failed: %s", e.what());
        return false;
    }
    
    is_connected_ = true;
    return true;
}

void TracerROSMessenger::PublishOdometryToROS(double linear, double angular, double dt)
{
    // Update speed values
    linear_speed_ = linear;
    angular_speed_ = angular;

    // Update position and orientation
    double d_x = linear_speed_ * std::cos(theta_) * dt;
    double d_y = linear_speed_ * std::sin(theta_) * dt;
    double d_theta = angular_speed_ * dt;

    position_x_ += d_x;
    position_y_ += d_y;
    theta_ += d_theta;

    // Normalize angle to [-π, π]
    while (theta_ > M_PI) theta_ -= 2.0 * M_PI;
    while (theta_ < -M_PI) theta_ += 2.0 * M_PI;

    // Create quaternion from yaw
    tf2::Quaternion q;
    q.setRPY(0, 0, theta_);
    geometry_msgs::msg::Quaternion odom_quat = tf2::toMsg(q);

    // Broadcast transform
    geometry_msgs::msg::TransformStamped tf_msg;
    tf_msg.header.stamp = current_time_;
    tf_msg.header.frame_id = odom_frame_;
    tf_msg.child_frame_id = base_frame_;

    tf_msg.transform.translation.x = position_x_;
    tf_msg.transform.translation.y = position_y_;
    tf_msg.transform.translation.z = 0.0;
    tf_msg.transform.rotation = odom_quat;

    // tf_broadcaster_->sendTransform(tf_msg);

    // Publish odometry message
    auto odom_msg = std::make_unique<nav_msgs::msg::Odometry>();
    odom_msg->header.stamp = current_time_;
    odom_msg->header.frame_id = odom_frame_;
    odom_msg->child_frame_id = base_frame_;

    odom_msg->pose.pose.position.x = position_x_;
    odom_msg->pose.pose.position.y = position_y_;
    odom_msg->pose.pose.position.z = 0.0;
    odom_msg->pose.pose.orientation = odom_quat;

    odom_msg->twist.twist.linear.x = linear_speed_;
    odom_msg->twist.twist.linear.y = 0.0;
    odom_msg->twist.twist.angular.z = angular_speed_;

    odom_publisher_->publish(std::move(odom_msg));
}

} // namespace westonrobot