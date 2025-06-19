// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tracer_msgs:msg/TracerMotorState.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__BUILDER_HPP_
#define TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tracer_msgs/msg/detail/tracer_motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tracer_msgs
{

namespace msg
{

namespace builder
{

class Init_TracerMotorState_rpm
{
public:
  Init_TracerMotorState_rpm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tracer_msgs::msg::TracerMotorState rpm(::tracer_msgs::msg::TracerMotorState::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tracer_msgs::msg::TracerMotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tracer_msgs::msg::TracerMotorState>()
{
  return tracer_msgs::msg::builder::Init_TracerMotorState_rpm();
}

}  // namespace tracer_msgs

#endif  // TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__BUILDER_HPP_
