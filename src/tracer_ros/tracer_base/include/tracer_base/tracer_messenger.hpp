#ifndef TRACER_MESSENGER_HPP
#define TRACER_MESSENGER_HPP

#include <string>
#include <memory>
#include <mutex>
#include <atomic>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tracer_msgs/msg/tracer_light_cmd.hpp>
#include <tracer_msgs/msg/tracer_status.hpp>

#include "ugv_sdk/mobile_robot/tracer_robot.hpp"

namespace westonrobot
{

class TracerROSMessenger
{
public:
    TracerROSMessenger(std::shared_ptr<TracerRobot> tracer, rclcpp::Node::SharedPtr nh);
    
    // Configuration parameters
    std::string port_name_;
    std::string odom_frame_;
    std::string base_frame_;
    bool simulated_robot_ = false;
    int sim_control_rate_ = 50;
    bool is_connected_ = false;  // Custom connection status

    // Check validity
    bool IsValid() const {
        return tracer_ != nullptr && nh_ != nullptr;
    }

    // Core functionality
    void SetupSubscription();
    bool PublishStateToROS();  // Returns success
    void PublishSimStateToROS(double linear, double angular);
    void GetCurrentMotionCmdForSim(double &linear, double &angular);
    bool AttemptReconnection(const std::string& port_name);  // Reconnect method
    
private:
    // Safe pointer management
    std::shared_ptr<TracerRobot> tracer_;
    rclcpp::Node::SharedPtr nh_;
    
    // Command mutex
    std::mutex twist_mutex_;
    geometry_msgs::msg::Twist current_twist_;
    
    // State mutex
    std::mutex state_mutex_;
    
    // ROS interfaces
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::Publisher<tracer_msgs::msg::TracerStatus>::SharedPtr status_publisher_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr motion_cmd_subscriber_;
    rclcpp::Subscription<tracer_msgs::msg::TracerLightCmd>::SharedPtr light_cmd_subscriber_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    // Pose and velocity state
    double linear_speed_ = 0.0;
    double angular_speed_ = 0.0;
    double position_x_ = 0.0;
    double position_y_ = 0.0;
    double theta_ = 0.0;
    
    rclcpp::Time last_time_;
    rclcpp::Time current_time_;
    bool first_publish_ = true;  // First publish flag

    // Callbacks and helper functions
    void TwistCmdCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void LightCmdCallback(const tracer_msgs::msg::TracerLightCmd::SharedPtr msg);
    void PublishOdometryToROS(double linear, double angular, double dt);
};

} // namespace westonrobot

#endif // TRACER_MESSENGER_HPP