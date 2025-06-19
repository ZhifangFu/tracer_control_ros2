// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tracer_msgs:msg/UartTracerMotorState.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__STRUCT_H_
#define TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/UartTracerMotorState in the package tracer_msgs.
typedef struct tracer_msgs__msg__UartTracerMotorState
{
  double current;
  double rpm;
  double temperature;
} tracer_msgs__msg__UartTracerMotorState;

// Struct for a sequence of tracer_msgs__msg__UartTracerMotorState.
typedef struct tracer_msgs__msg__UartTracerMotorState__Sequence
{
  tracer_msgs__msg__UartTracerMotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracer_msgs__msg__UartTracerMotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRACER_MSGS__MSG__DETAIL__UART_TRACER_MOTOR_STATE__STRUCT_H_
