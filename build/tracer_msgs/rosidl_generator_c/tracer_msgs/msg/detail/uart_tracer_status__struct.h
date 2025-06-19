// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tracer_msgs:msg/UartTracerStatus.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_H_
#define TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MOTOR_ID_FRONT_RIGHT'.
enum
{
  tracer_msgs__msg__UartTracerStatus__MOTOR_ID_FRONT_RIGHT = 0
};

/// Constant 'MOTOR_ID_FRONT_LEFT'.
enum
{
  tracer_msgs__msg__UartTracerStatus__MOTOR_ID_FRONT_LEFT = 1
};

/// Constant 'MOTOR_ID_REAR_RIGHT'.
enum
{
  tracer_msgs__msg__UartTracerStatus__MOTOR_ID_REAR_RIGHT = 2
};

/// Constant 'MOTOR_ID_REAR_LEFT'.
enum
{
  tracer_msgs__msg__UartTracerStatus__MOTOR_ID_REAR_LEFT = 3
};

/// Constant 'LIGHT_ID_FRONT'.
enum
{
  tracer_msgs__msg__UartTracerStatus__LIGHT_ID_FRONT = 0
};

/// Constant 'LIGHT_ID_REAR'.
enum
{
  tracer_msgs__msg__UartTracerStatus__LIGHT_ID_REAR = 1
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'motor_states'
#include "tracer_msgs/msg/detail/uart_tracer_motor_state__struct.h"
// Member 'front_light_state'
// Member 'rear_light_state'
#include "tracer_msgs/msg/detail/tracer_light_state__struct.h"

/// Struct defined in msg/UartTracerStatus in the package tracer_msgs.
typedef struct tracer_msgs__msg__UartTracerStatus
{
  std_msgs__msg__Header header;
  /// motion state
  double linear_velocity;
  double angular_velocity;
  /// base state
  uint8_t base_state;
  uint8_t control_mode;
  uint16_t fault_code;
  double battery_voltage;
  /// motor state
  tracer_msgs__msg__UartTracerMotorState motor_states[2];
  /// light state
  bool light_control_enabled;
  tracer_msgs__msg__TracerLightState front_light_state;
  tracer_msgs__msg__TracerLightState rear_light_state;
} tracer_msgs__msg__UartTracerStatus;

// Struct for a sequence of tracer_msgs__msg__UartTracerStatus.
typedef struct tracer_msgs__msg__UartTracerStatus__Sequence
{
  tracer_msgs__msg__UartTracerStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracer_msgs__msg__UartTracerStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRACER_MSGS__MSG__DETAIL__UART_TRACER_STATUS__STRUCT_H_
