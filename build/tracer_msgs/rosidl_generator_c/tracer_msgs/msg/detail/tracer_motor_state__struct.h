// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tracer_msgs:msg/TracerMotorState.idl
// generated code does not contain a copyright notice

#ifndef TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__STRUCT_H_
#define TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TracerMotorState in the package tracer_msgs.
/**
  * float64 current
 */
typedef struct tracer_msgs__msg__TracerMotorState
{
  double rpm;
} tracer_msgs__msg__TracerMotorState;

// Struct for a sequence of tracer_msgs__msg__TracerMotorState.
typedef struct tracer_msgs__msg__TracerMotorState__Sequence
{
  tracer_msgs__msg__TracerMotorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tracer_msgs__msg__TracerMotorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TRACER_MSGS__MSG__DETAIL__TRACER_MOTOR_STATE__STRUCT_H_
