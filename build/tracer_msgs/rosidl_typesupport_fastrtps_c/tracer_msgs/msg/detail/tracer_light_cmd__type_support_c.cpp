// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from tracer_msgs:msg/TracerLightCmd.idl
// generated code does not contain a copyright notice
#include "tracer_msgs/msg/detail/tracer_light_cmd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "tracer_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "tracer_msgs/msg/detail/tracer_light_cmd__struct.h"
#include "tracer_msgs/msg/detail/tracer_light_cmd__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _TracerLightCmd__ros_msg_type = tracer_msgs__msg__TracerLightCmd;

static bool _TracerLightCmd__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _TracerLightCmd__ros_msg_type * ros_message = static_cast<const _TracerLightCmd__ros_msg_type *>(untyped_ros_message);
  // Field name: enable_cmd_light_control
  {
    cdr << (ros_message->enable_cmd_light_control ? true : false);
  }

  // Field name: front_mode
  {
    cdr << ros_message->front_mode;
  }

  // Field name: front_custom_value
  {
    cdr << ros_message->front_custom_value;
  }

  // Field name: rear_mode
  {
    cdr << ros_message->rear_mode;
  }

  // Field name: rear_custom_value
  {
    cdr << ros_message->rear_custom_value;
  }

  return true;
}

static bool _TracerLightCmd__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TracerLightCmd__ros_msg_type * ros_message = static_cast<_TracerLightCmd__ros_msg_type *>(untyped_ros_message);
  // Field name: enable_cmd_light_control
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->enable_cmd_light_control = tmp ? true : false;
  }

  // Field name: front_mode
  {
    cdr >> ros_message->front_mode;
  }

  // Field name: front_custom_value
  {
    cdr >> ros_message->front_custom_value;
  }

  // Field name: rear_mode
  {
    cdr >> ros_message->rear_mode;
  }

  // Field name: rear_custom_value
  {
    cdr >> ros_message->rear_custom_value;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tracer_msgs
size_t get_serialized_size_tracer_msgs__msg__TracerLightCmd(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _TracerLightCmd__ros_msg_type * ros_message = static_cast<const _TracerLightCmd__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name enable_cmd_light_control
  {
    size_t item_size = sizeof(ros_message->enable_cmd_light_control);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name front_mode
  {
    size_t item_size = sizeof(ros_message->front_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name front_custom_value
  {
    size_t item_size = sizeof(ros_message->front_custom_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rear_mode
  {
    size_t item_size = sizeof(ros_message->rear_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name rear_custom_value
  {
    size_t item_size = sizeof(ros_message->rear_custom_value);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TracerLightCmd__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_tracer_msgs__msg__TracerLightCmd(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_tracer_msgs
size_t max_serialized_size_tracer_msgs__msg__TracerLightCmd(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: enable_cmd_light_control
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: front_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: front_custom_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rear_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: rear_custom_value
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = tracer_msgs__msg__TracerLightCmd;
    is_plain =
      (
      offsetof(DataType, rear_custom_value) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _TracerLightCmd__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_tracer_msgs__msg__TracerLightCmd(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_TracerLightCmd = {
  "tracer_msgs::msg",
  "TracerLightCmd",
  _TracerLightCmd__cdr_serialize,
  _TracerLightCmd__cdr_deserialize,
  _TracerLightCmd__get_serialized_size,
  _TracerLightCmd__max_serialized_size
};

static rosidl_message_type_support_t _TracerLightCmd__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_TracerLightCmd,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, tracer_msgs, msg, TracerLightCmd)() {
  return &_TracerLightCmd__type_support;
}

#if defined(__cplusplus)
}
#endif
