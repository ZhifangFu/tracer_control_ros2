// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tracer_msgs:msg/UartTracerMotorState.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__BUILDER_HPP_
#define TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tracer_msgs/msg/detail/uart_tracer_motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tracer_msgs
{

namespace msg
{

namespace builder
{

class Init_UartTracerMotorState_temperature
{
public:
  explicit Init_UartTracerMotorState_temperature(::tracer_msgs::msg::UartTracerMotorState & msg)
  : msg_(msg)
  {}
  ::tracer_msgs::msg::UartTracerMotorState temperature(::tracer_msgs::msg::UartTracerMotorState::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerMotorState msg_;
};

class Init_UartTracerMotorState_rpm
{
public:
  explicit Init_UartTracerMotorState_rpm(::tracer_msgs::msg::UartTracerMotorState & msg)
  : msg_(msg)
  {}
  Init_UartTracerMotorState_temperature rpm(::tracer_msgs::msg::UartTracerMotorState::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return Init_UartTracerMotorState_temperature(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerMotorState msg_;
};

class Init_UartTracerMotorState_current
{
public:
  Init_UartTracerMotorState_current()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UartTracerMotorState_rpm current(::tracer_msgs::msg::UartTracerMotorState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_UartTracerMotorState_rpm(msg_);
  }

private:
  ::tracer_msgs::msg::UartTracerMotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracer_msgs::msg::UartTracerMotorState>()
{
  return tracer_msgs::msg::builder::Init_UartTracerMotorState_current();
}

}  // namespace tracer_msgs

#endif  // TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__BUILDER_HPP_
