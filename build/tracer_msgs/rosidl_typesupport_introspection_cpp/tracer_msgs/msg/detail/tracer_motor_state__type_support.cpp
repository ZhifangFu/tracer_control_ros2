// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tracer_msgs:msg/TracerMotorState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tracer_msgs/msg/detail/tracer_motor_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tracer_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TracerMotorState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tracer_msgs::msg::TracerMotorState(_init);
}

void TracerMotorState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tracer_msgs::msg::TracerMotorState *>(message_memory);
  typed_message->~TracerMotorState();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TracerMotorState_message_member_array[1] = {
  {
    "rpm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tracer_msgs::msg::TracerMotorState, rpm),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TracerMotorState_message_members = {
  "tracer_msgs::msg",  // message namespace
  "TracerMotorState",  // message name
  1,  // number of fields
  sizeof(tracer_msgs::msg::TracerMotorState),
  TracerMotorState_message_member_array,  // message members
  TracerMotorState_init_function,  // function to initialize message memory (memory has to be allocated)
  TracerMotorState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TracerMotorState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TracerMotorState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tracer_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tracer_msgs::msg::TracerMotorState>()
{
  return &::tracer_msgs::msg::rosidl_typesupport_introspection_cpp::TracerMotorState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tracer_msgs, msg, TracerMotorState)() {
  return &::tracer_msgs::msg::rosidl_typesupport_introspection_cpp::TracerMotorState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
