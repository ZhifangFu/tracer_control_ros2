// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tracer_msgs:msg/TracerMotorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tracer_msgs/msg/detail/tracer_motor_state__rosidl_typesupport_introspection_c.h"
#include "tracer_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tracer_msgs/msg/detail/tracer_motor_state__functions.h"
#include "tracer_msgs/msg/detail/tracer_motor_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tracer_msgs__msg__TracerMotorState__init(message_memory);
}

void tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_fini_function(void * message_memory)
{
  tracer_msgs__msg__TracerMotorState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_member_array[1] = {
  {
    "rpm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs__msg__TracerMotorState, rpm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_members = {
  "tracer_msgs__msg",  // message namespace
  "TracerMotorState",  // message name
  1,  // number of fields
  sizeof(tracer_msgs__msg__TracerMotorState),
  tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_member_array,  // message members
  tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_type_support_handle = {
  0,
  &tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tracer_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tracer_msgs, msg, TracerMotorState)() {
  if (!tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_type_support_handle.typesupport_identifier) {
    tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tracer_msgs__msg__TracerMotorState__rosidl_typesupport_introspection_c__TracerMotorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
