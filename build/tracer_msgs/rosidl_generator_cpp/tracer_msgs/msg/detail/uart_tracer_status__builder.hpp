// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tracer_msgs:msg/UartTracerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__BUILDER_HPP_
#define TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tracer_msgs/msg/detail/uart_tracer_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tracer_msgs
{

namespace msg
{

namespace builder
{

class Init_UartTracerStatus_rear_light_state
{
public:
  explicit Init_UartTracerStatus_rear_light_state(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  ::tracer_msgs::msg::UartTracerStatus rear_light_state(::tracer_msgs::msg::UartTracerStatus::_rear_light_state_type arg)
  {
    msg_.rear_light_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_front_light_state
{
public:
  explicit Init_UartTracerStatus_front_light_state(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_rear_light_state front_light_state(::tracer_msgs::msg::UartTracerStatus::_front_light_state_type arg)
  {
    msg_.front_light_state = std::move(arg);
    return Init_UartTracerStatus_rear_light_state(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_light_control_enabled
{
public:
  explicit Init_UartTracerStatus_light_control_enabled(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_front_light_state light_control_enabled(::tracer_msgs::msg::UartTracerStatus::_light_control_enabled_type arg)
  {
    msg_.light_control_enabled = std::move(arg);
    return Init_UartTracerStatus_front_light_state(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_motor_states
{
public:
  explicit Init_UartTracerStatus_motor_states(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_light_control_enabled motor_states(::tracer_msgs::msg::UartTracerStatus::_motor_states_type arg)
  {
    msg_.motor_states = std::move(arg);
    return Init_UartTracerStatus_light_control_enabled(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_battery_voltage
{
public:
  explicit Init_UartTracerStatus_battery_voltage(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_motor_states battery_voltage(::tracer_msgs::msg::UartTracerStatus::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_UartTracerStatus_motor_states(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_fault_code
{
public:
  explicit Init_UartTracerStatus_fault_code(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_battery_voltage fault_code(::tracer_msgs::msg::UartTracerStatus::_fault_code_type arg)
  {
    msg_.fault_code = std::move(arg);
    return Init_UartTracerStatus_battery_voltage(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_control_mode
{
public:
  explicit Init_UartTracerStatus_control_mode(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_fault_code control_mode(::tracer_msgs::msg::UartTracerStatus::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_UartTracerStatus_fault_code(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_base_state
{
public:
  explicit Init_UartTracerStatus_base_state(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_control_mode base_state(::tracer_msgs::msg::UartTracerStatus::_base_state_type arg)
  {
    msg_.base_state = std::move(arg);
    return Init_UartTracerStatus_control_mode(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_angular_velocity
{
public:
  explicit Init_UartTracerStatus_angular_velocity(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_base_state angular_velocity(::tracer_msgs::msg::UartTracerStatus::_angular_velocity_type arg)
  {
    msg_.angular_velocity = std::move(arg);
    return Init_UartTracerStatus_base_state(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_linear_velocity
{
public:
  explicit Init_UartTracerStatus_linear_velocity(::tracer_msgs::msg::UartTracerStatus & msg)
  : msg_(msg)
  {}
  Init_UartTracerStatus_angular_velocity linear_velocity(::tracer_msgs::msg::UartTracerStatus::_linear_velocity_type arg)
  {
    msg_.linear_velocity = std::move(arg);
    return Init_UartTracerStatus_angular_velocity(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

class Init_UartTracerStatus_header
{
public:
  Init_UartTracerStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UartTracerStatus_linear_velocity header(::tracer_msgs::msg::UartTracerStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_UartTracerStatus_linear_velocity(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracer_msgs::msg::UartTracerStatus>()
{
  return tracer_msgs::msg::builder::Init_UartTracerStatus_header();
}

}  // namespace tracer_msgs

#endif  // TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__BUILDER_HPP_
