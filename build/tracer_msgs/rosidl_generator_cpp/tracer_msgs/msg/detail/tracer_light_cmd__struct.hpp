// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tracer_msgs:msg/TracerLightCmd.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__TRACER_LIGHT_CMD__STRUCT_HPP_
#define TRACER_MSGS__MSG__DETAIL__TRACER_LIGHT_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tracer_msgs__msg__TracerLightCmd __attribute__((deprecated))
#else
# define DEPRECATED__tracer_msgs__msg__TracerLightCmd __declspec(deprecated)
#endif

namespace tracer_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TracerLightCmd_
{
  using Type = TracerLightCmd_<ContainerAllocator>;

  explicit TracerLightCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_cmd_light_control = false;
      this->front_mode = 0;
      this->front_custom_value = 0;
      this->rear_mode = 0;
      this->rear_custom_value = 0;
    }
  }

  explicit TracerLightCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_cmd_light_control = false;
      this->front_mode = 0;
      this->front_custom_value = 0;
      this->rear_mode = 0;
      this->rear_custom_value = 0;
    }
  }

  // field types and members
  using _enable_cmd_light_control_type =
    bool;
  _enable_cmd_light_control_type enable_cmd_light_control;
  using _front_mode_type =
    uint8_t;
  _front_mode_type front_mode;
  using _front_custom_value_type =
    uint8_t;
  _front_custom_value_type front_custom_value;
  using _rear_mode_type =
    uint8_t;
  _rear_mode_type rear_mode;
  using _rear_custom_value_type =
    uint8_t;
  _rear_custom_value_type rear_custom_value;

  // setters for named parameter idiom
  Type & set__enable_cmd_light_control(
    const bool & _arg)
  {
    this->enable_cmd_light_control = _arg;
    return *this;
  }
  Type & set__front_mode(
    const uint8_t & _arg)
  {
    this->front_mode = _arg;
    return *this;
  }
  Type & set__front_custom_value(
    const uint8_t & _arg)
  {
    this->front_custom_value = _arg;
    return *this;
  }
  Type & set__rear_mode(
    const uint8_t & _arg)
  {
    this->rear_mode = _arg;
    return *this;
  }
  Type & set__rear_custom_value(
    const uint8_t & _arg)
  {
    this->rear_custom_value = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t LIGHT_CONST_OFF =
    0u;
  static constexpr uint8_t LIGHT_CONST_ON =
    1u;
  static constexpr uint8_t LIGHT_BREATH =
    2u;
  static constexpr uint8_t LIGHT_CUSTOM =
    3u;

  // pointer types
  using RawPtr =
    tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tracer_msgs__msg__TracerLightCmd
    std::shared_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tracer_msgs__msg__TracerLightCmd
    std::shared_ptr<tracer_msgs::msg::TracerLightCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TracerLightCmd_ & other) const
  {
    if (this->enable_cmd_light_control != other.enable_cmd_light_control) {
      return false;
    }
    if (this->front_mode != other.front_mode) {
      return false;
    }
    if (this->front_custom_value != other.front_custom_value) {
      return false;
    }
    if (this->rear_mode != other.rear_mode) {
      return false;
    }
    if (this->rear_custom_value != other.rear_custom_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const TracerLightCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TracerLightCmd_

// alias to use template instance with default allocator
using TracerLightCmd =
  tracer_msgs::msg::TracerLightCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TracerLightCmd_<ContainerAllocator>::LIGHT_CONST_OFF;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TracerLightCmd_<ContainerAllocator>::LIGHT_CONST_ON;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TracerLightCmd_<ContainerAllocator>::LIGHT_BREATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TracerLightCmd_<ContainerAllocator>::LIGHT_CUSTOM;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tracer_msgs

#endif  // TRACER_MSGS__MSG__DETAIL__TRACER_LIGHT_CMD__STRUCT_HPP_
