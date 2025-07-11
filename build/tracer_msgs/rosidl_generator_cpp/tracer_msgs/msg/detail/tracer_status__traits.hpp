// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tracer_msgs:msg/TracerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__TRACER_STATUS__TRAITS_HPP_
#define TRACER_MSGS__MSG__DETAIL__TRACER_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tracer_msgs/msg/detail/tracer_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'motor_states'
#include "tracer_msgs/msg/detail/tracer_motor_state__traits.hpp"
// Member 'front_light_state'
#include "tracer_msgs/msg/detail/tracer_light_state__traits.hpp"

namespace tracer_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const TracerStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: linear_velocity
  {
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << ", ";
  }

  // member: angular_velocity
  {
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
    out << ", ";
  }

  // member: base_state
  {
    out << "base_state: ";
    rosidl_generator_traits::value_to_yaml(msg.base_state, out);
    out << ", ";
  }

  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: fault_code
  {
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
    out << ", ";
  }

  // member: battery_voltage
  {
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << ", ";
  }

  // member: motor_states
  {
    if (msg.motor_states.size() == 0) {
      out << "motor_states: []";
    } else {
      out << "motor_states: [";
      size_t pending_items = msg.motor_states.size();
      for (auto item : msg.motor_states) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: light_control_enabled
  {
    out << "light_control_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.light_control_enabled, out);
    out << ", ";
  }

  // member: front_light_state
  {
    out << "front_light_state: ";
    to_flow_style_yaml(msg.front_light_state, out);
    out << ", ";
  }

  // member: left_odomter
  {
    out << "left_odomter: ";
    rosidl_generator_traits::value_to_yaml(msg.left_odomter, out);
    out << ", ";
  }

  // member: right_odomter
  {
    out << "right_odomter: ";
    rosidl_generator_traits::value_to_yaml(msg.right_odomter, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TracerStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: linear_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_velocity, out);
    out << "\n";
  }

  // member: angular_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_velocity, out);
    out << "\n";
  }

  // member: base_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "base_state: ";
    rosidl_generator_traits::value_to_yaml(msg.base_state, out);
    out << "\n";
  }

  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: fault_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_code: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_code, out);
    out << "\n";
  }

  // member: battery_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_voltage, out);
    out << "\n";
  }

  // member: motor_states
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_states.size() == 0) {
      out << "motor_states: []\n";
    } else {
      out << "motor_states:\n";
      for (auto item : msg.motor_states) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: light_control_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "light_control_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.light_control_enabled, out);
    out << "\n";
  }

  // member: front_light_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "front_light_state:\n";
    to_block_style_yaml(msg.front_light_state, out, indentation + 2);
  }

  // member: left_odomter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_odomter: ";
    rosidl_generator_traits::value_to_yaml(msg.left_odomter, out);
    out << "\n";
  }

  // member: right_odomter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_odomter: ";
    rosidl_generator_traits::value_to_yaml(msg.right_odomter, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TracerStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tracer_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tracer_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tracer_msgs::msg::TracerStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  tracer_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tracer_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tracer_msgs::msg::TracerStatus & msg)
{
  return tracer_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tracer_msgs::msg::TracerStatus>()
{
  return "tracer_msgs::msg::TracerStatus";
}

template<>
inline const char * name<tracer_msgs::msg::TracerStatus>()
{
  return "tracer_msgs/msg/TracerStatus";
}

template<>
struct has_fixed_size<tracer_msgs::msg::TracerStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value && has_fixed_size<tracer_msgs::msg::TracerLightState>::value && has_fixed_size<tracer_msgs::msg::TracerMotorState>::value> {};

template<>
struct has_bounded_size<tracer_msgs::msg::TracerStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value && has_bounded_size<tracer_msgs::msg::TracerLightState>::value && has_bounded_size<tracer_msgs::msg::TracerMotorState>::value> {};

template<>
struct is_message<tracer_msgs::msg::TracerStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TRACER_MSGS__MSG__DETAIL__TRACER_STATUS__TRAITS_HPP_
