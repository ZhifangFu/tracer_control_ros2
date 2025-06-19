// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tracer_msgs:msg/UartTracerStatus.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tracer_msgs/msg/detail/uart_tracer_status__rosidl_typesupport_introspection_c.h"
#include "tracer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tracer_msgs/msg/detail/uart_tracer_status__functions.h"
#include "tracer_msgs/msg/detail/uart_tracer_status__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `motor_states`
#include "tracer_msgs/msg/uart_tracer_motor_state.h"
// Member `motor_states`
#include "tracer_msgs/msg/detail/uart_tracer_motor_state__rosidl_typesupport_introspection_c.h"
// Member `front_light_state`
// Member `rear_light_state`
#include "tracer_msgs/msg/tracer_light_state.h"
// Member `front_light_state`
// Member `rear_light_state`
#include "tracer_msgs/msg/detail/tracer_light_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracer_msgs__msg__UartTracerStatus__init(message_memory);
}

void tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_fini_function(void * message_memory)
{
  tracer_msgs__msg__UartTracerStatus__fini(message_memory);
}

size_t tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__size_function__UartTracerStatus__motor_states(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_const_function__UartTracerStatus__motor_states(
  const void * untyped_member, size_t index)
{
  const tracer_msgs__msg__UartTracerMotorState * member =
    (const tracer_msgs__msg__UartTracerMotorState *)(untyped_member);
  return &member[index];
}

void * tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_function__UartTracerStatus__motor_states(
  void * untyped_member, size_t index)
{
  tracer_msgs__msg__UartTracerMotorState * member =
    (tracer_msgs__msg__UartTracerMotorState *)(untyped_member);
  return &member[index];
}

void tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__fetch_function__UartTracerStatus__motor_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tracer_msgs__msg__UartTracerMotorState * item =
    ((const tracer_msgs__msg__UartTracerMotorState *)
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_const_function__UartTracerStatus__motor_states(untyped_member, index));
  tracer_msgs__msg__UartTracerMotorState * value =
    (tracer_msgs__msg__UartTracerMotorState *)(untyped_value);
  *value = *item;
}

void tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__assign_function__UartTracerStatus__motor_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tracer_msgs__msg__UartTracerMotorState * item =
    ((tracer_msgs__msg__UartTracerMotorState *)
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_function__UartTracerStatus__motor_states(untyped_member, index));
  const tracer_msgs__msg__UartTracerMotorState * value =
    (const tracer_msgs__msg__UartTracerMotorState *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array[11] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "linear_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, linear_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "angular_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, angular_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, base_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "control_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, control_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "fault_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, fault_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "battery_voltage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, battery_voltage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, motor_states),  // bytes offset in struct
    NULL,  // default value
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__size_function__UartTracerStatus__motor_states,  // size() function pointer
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_const_function__UartTracerStatus__motor_states,  // get_const(index) function pointer
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__get_function__UartTracerStatus__motor_states,  // get(index) function pointer
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__fetch_function__UartTracerStatus__motor_states,  // fetch(index, &value) function pointer
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__assign_function__UartTracerStatus__motor_states,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "light_control_enabled",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, light_control_enabled),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "front_light_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, front_light_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rear_light_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__UartTracerStatus, rear_light_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_members = {
  "tracer_msgs__msg",  // message namespace
  "UartTracerStatus",  // message name
  11,  // number of fields
  sizeof(tracer_msgs__msg__UartTracerStatus),
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array,  // message members
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_type_support_handle = {
  0,
  &tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracer_msgs, msg, UartTracerStatus)() {
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracer_msgs, msg, UartTracerMotorState)();
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracer_msgs, msg, TracerLightState)();
  tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracer_msgs, msg, TracerLightState)();
  if (!tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_type_support_handle.typesupport_identifier) {
    tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracer_msgs__msg__UartTracerStatus__rosidl_typesupport_introspection_c__UartTracerStatus_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
