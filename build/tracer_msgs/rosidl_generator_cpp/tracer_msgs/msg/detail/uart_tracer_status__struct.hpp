// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tracer_msgs:msg/UartTracerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_HPP_
#define TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'motor_states'
#include "tracer_msgs/msg/detail/uart_tracer_motor_state__struct.hpp"
// Member 'front_light_state'
// Member 'rear_light_state'
#include "tracer_msgs/msg/detail/tracer_light_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tracer_msgs__msg__UartTracerStatus __attribute__((deprecated))
#else
# define DEPRECATED__tracer_msgs__msg__UartTracerStatus __declspec(deprecated)
#endif

namespace tracer_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UartTracerStatus_
{
  using Type = UartTracerStatus_<ContainerAllocator>;

  explicit UartTracerStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    front_light_state(_init),
    rear_light_state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_velocity = 0.0;
      this->angular_velocity = 0.0;
      this->base_state = 0;
      this->control_mode = 0;
      this->fault_code = 0;
      this->battery_voltage = 0.0;
      this->motor_states.fill(tracer_msgs::msg::UartTracerMotorState_<ContainerAllocator>{_init});
      this->light_control_enabled = false;
    }
  }

  explicit UartTracerStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    motor_states(_alloc),
    front_light_state(_alloc, _init),
    rear_light_state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_velocity = 0.0;
      this->angular_velocity = 0.0;
      this->base_state = 0;
      this->control_mode = 0;
      this->fault_code = 0;
      this->battery_voltage = 0.0;
      this->motor_states.fill(tracer_msgs::msg::UartTracerMotorState_<ContainerAllocator>{_alloc, _init});
      this->light_control_enabled = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _linear_velocity_type =
    double;
  _linear_velocity_type linear_velocity;
  using _angular_velocity_type =
    double;
  _angular_velocity_type angular_velocity;
  using _base_state_type =
    uint8_t;
  _base_state_type base_state;
  using _control_mode_type =
    uint8_t;
  _control_mode_type control_mode;
  using _fault_code_type =
    uint16_t;
  _fault_code_type fault_code;
  using _battery_voltage_type =
    double;
  _battery_voltage_type battery_voltage;
  using _motor_states_type =
    std::array<tracer_msgs::msg::UartTracerMotorState_<ContainerAllocator>, 2>;
  _motor_states_type motor_states;
  using _light_control_enabled_type =
    bool;
  _light_control_enabled_type light_control_enabled;
  using _front_light_state_type =
    tracer_msgs::msg::TracerLightState_<ContainerAllocator>;
  _front_light_state_type front_light_state;
  using _rear_light_state_type =
    tracer_msgs::msg::TracerLightState_<ContainerAllocator>;
  _rear_light_state_type rear_light_state;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__linear_velocity(
    const double & _arg)
  {
    this->linear_velocity = _arg;
    return *this;
  }
  Type & set__angular_velocity(
    const double & _arg)
  {
    this->angular_velocity = _arg;
    return *this;
  }
  Type & set__base_state(
    const uint8_t & _arg)
  {
    this->base_state = _arg;
    return *this;
  }
  Type & set__control_mode(
    const uint8_t & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__fault_code(
    const uint16_t & _arg)
  {
    this->fault_code = _arg;
    return *this;
  }
  Type & set__battery_voltage(
    const double & _arg)
  {
    this->battery_voltage = _arg;
    return *this;
  }
  Type & set__motor_states(
    const std::array<tracer_msgs::msg::UartTracerMotorState_<ContainerAllocator>, 2> & _arg)
  {
    this->motor_states = _arg;
    return *this;
  }
  Type & set__light_control_enabled(
    const bool & _arg)
  {
    this->light_control_enabled = _arg;
    return *this;
  }
  Type & set__front_light_state(
    const tracer_msgs::msg::TracerLightState_<ContainerAllocator> & _arg)
  {
    this->front_light_state = _arg;
    return *this;
  }
  Type & set__rear_light_state(
    const tracer_msgs::msg::TracerLightState_<ContainerAllocator> & _arg)
  {
    this->rear_light_state = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t MOTOR_ID_FRONT_RIGHT =
    0;
  static constexpr int8_t MOTOR_ID_FRONT_LEFT =
    1;
  static constexpr int8_t MOTOR_ID_REAR_RIGHT =
    2;
  static constexpr int8_t MOTOR_ID_REAR_LEFT =
    3;
  static constexpr int8_t LIGHT_ID_FRONT =
    0;
  static constexpr int8_t LIGHT_ID_REAR =
    1;

  // pointer types
  using RawPtr =
    tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tracer_msgs__msg__UartTracerStatus
    std::shared_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tracer_msgs__msg__UartTracerStatus
    std::shared_ptr<tracer_msgs::msg::UartTracerStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UartTracerStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->linear_velocity != other.linear_velocity) {
      return false;
    }
    if (this->angular_velocity != other.angular_velocity) {
      return false;
    }
    if (this->base_state != other.base_state) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->fault_code != other.fault_code) {
      return false;
    }
    if (this->battery_voltage != other.battery_voltage) {
      return false;
    }
    if (this->motor_states != other.motor_states) {
      return false;
    }
    if (this->light_control_enabled != other.light_control_enabled) {
      return false;
    }
    if (this->front_light_state != other.front_light_state) {
      return false;
    }
    if (this->rear_light_state != other.rear_light_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const UartTracerStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UartTracerStatus_

// alias to use template instance with default allocator
using UartTracerStatus =
  tracer_msgs::msg::UartTracerStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::MOTOR_ID_FRONT_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::MOTOR_ID_FRONT_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::MOTOR_ID_REAR_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::MOTOR_ID_REAR_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::LIGHT_ID_FRONT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t UartTracerStatus_<ContainerAllocator>::LIGHT_ID_REAR;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tracer_msgs

#endif  // TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_HPP_
