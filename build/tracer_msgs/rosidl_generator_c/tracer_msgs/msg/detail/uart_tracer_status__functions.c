// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tracer_msgs:msg/UartTracerStatus.idl
// generated code does not contain a copyright notice
#include "tracer_msgs/msg/detail/uart_tracer_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `motor_states`
#include "tracer_msgs/msg/detail/uart_tracer_motor_state__functions.h"
// Member `front_light_state`
// Member `rear_light_state`
#include "tracer_msgs/msg/detail/tracer_light_state__functions.h"

bool
tracer_msgs__msg__UartTracerStatus__init(tracer_msgs__msg__UartTracerStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    tracer_msgs__msg__UartTracerStatus__fini(msg);
    return false;
  }
  // linear_velocity
  // angular_velocity
  // base_state
  // control_mode
  // fault_code
  // battery_voltage
  // motor_states
  for (size_t i = 0; i < 2; ++i) {
    if (!tracer_msgs__msg__UartTracerMotorState__init(&msg->motor_states[i])) {
      tracer_msgs__msg__UartTracerStatus__fini(msg);
      return false;
    }
  }
  // light_control_enabled
  // front_light_state
  if (!tracer_msgs__msg__TracerLightState__init(&msg->front_light_state)) {
    tracer_msgs__msg__UartTracerStatus__fini(msg);
    return false;
  }
  // rear_light_state
  if (!tracer_msgs__msg__TracerLightState__init(&msg->rear_light_state)) {
    tracer_msgs__msg__UartTracerStatus__fini(msg);
    return false;
  }
  return true;
}

void
tracer_msgs__msg__UartTracerStatus__fini(tracer_msgs__msg__UartTracerStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // linear_velocity
  // angular_velocity
  // base_state
  // control_mode
  // fault_code
  // battery_voltage
  // motor_states
  for (size_t i = 0; i < 2; ++i) {
    tracer_msgs__msg__UartTracerMotorState__fini(&msg->motor_states[i]);
  }
  // light_control_enabled
  // front_light_state
  tracer_msgs__msg__TracerLightState__fini(&msg->front_light_state);
  // rear_light_state
  tracer_msgs__msg__TracerLightState__fini(&msg->rear_light_state);
}

bool
tracer_msgs__msg__UartTracerStatus__are_equal(const tracer_msgs__msg__UartTracerStatus * lhs, const tracer_msgs__msg__UartTracerStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // linear_velocity
  if (lhs->linear_velocity != rhs->linear_velocity) {
    return false;
  }
  // angular_velocity
  if (lhs->angular_velocity != rhs->angular_velocity) {
    return false;
  }
  // base_state
  if (lhs->base_state != rhs->base_state) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // fault_code
  if (lhs->fault_code != rhs->fault_code) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // motor_states
  for (size_t i = 0; i < 2; ++i) {
    if (!tracer_msgs__msg__UartTracerMotorState__are_equal(
        &(lhs->motor_states[i]), &(rhs->motor_states[i])))
    {
      return false;
    }
  }
  // light_control_enabled
  if (lhs->light_control_enabled != rhs->light_control_enabled) {
    return false;
  }
  // front_light_state
  if (!tracer_msgs__msg__TracerLightState__are_equal(
      &(lhs->front_light_state), &(rhs->front_light_state)))
  {
    return false;
  }
  // rear_light_state
  if (!tracer_msgs__msg__TracerLightState__are_equal(
      &(lhs->rear_light_state), &(rhs->rear_light_state)))
  {
    return false;
  }
  return true;
}

bool
tracer_msgs__msg__UartTracerStatus__copy(
  const tracer_msgs__msg__UartTracerStatus * input,
  tracer_msgs__msg__UartTracerStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // linear_velocity
  output->linear_velocity = input->linear_velocity;
  // angular_velocity
  output->angular_velocity = input->angular_velocity;
  // base_state
  output->base_state = input->base_state;
  // control_mode
  output->control_mode = input->control_mode;
  // fault_code
  output->fault_code = input->fault_code;
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // motor_states
  for (size_t i = 0; i < 2; ++i) {
    if (!tracer_msgs__msg__UartTracerMotorState__copy(
        &(input->motor_states[i]), &(output->motor_states[i])))
    {
      return false;
    }
  }
  // light_control_enabled
  output->light_control_enabled = input->light_control_enabled;
  // front_light_state
  if (!tracer_msgs__msg__TracerLightState__copy(
      &(input->front_light_state), &(output->front_light_state)))
  {
    return false;
  }
  // rear_light_state
  if (!tracer_msgs__msg__TracerLightState__copy(
      &(input->rear_light_state), &(output->rear_light_state)))
  {
    return false;
  }
  return true;
}

tracer_msgs__msg__UartTracerStatus *
tracer_msgs__msg__UartTracerStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerStatus * msg = (tracer_msgs__msg__UartTracerStatus *)allocator.allocate(sizeof(tracer_msgs__msg__UartTracerStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tracer_msgs__msg__UartTracerStatus));
  bool success = tracer_msgs__msg__UartTracerStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tracer_msgs__msg__UartTracerStatus__destroy(tracer_msgs__msg__UartTracerStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tracer_msgs__msg__UartTracerStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tracer_msgs__msg__UartTracerStatus__Sequence__init(tracer_msgs__msg__UartTracerStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerStatus * data = NULL;

  if (size) {
    data = (tracer_msgs__msg__UartTracerStatus *)allocator.zero_allocate(size, sizeof(tracer_msgs__msg__UartTracerStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tracer_msgs__msg__UartTracerStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tracer_msgs__msg__UartTracerStatus__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tracer_msgs__msg__UartTracerStatus__Sequence__fini(tracer_msgs__msg__UartTracerStatus__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tracer_msgs__msg__UartTracerStatus__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tracer_msgs__msg__UartTracerStatus__Sequence *
tracer_msgs__msg__UartTracerStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerStatus__Sequence * array = (tracer_msgs__msg__UartTracerStatus__Sequence *)allocator.allocate(sizeof(tracer_msgs__msg__UartTracerStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tracer_msgs__msg__UartTracerStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tracer_msgs__msg__UartTracerStatus__Sequence__destroy(tracer_msgs__msg__UartTracerStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tracer_msgs__msg__UartTracerStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tracer_msgs__msg__UartTracerStatus__Sequence__are_equal(const tracer_msgs__msg__UartTracerStatus__Sequence * lhs, const tracer_msgs__msg__UartTracerStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tracer_msgs__msg__UartTracerStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tracer_msgs__msg__UartTracerStatus__Sequence__copy(
  const tracer_msgs__msg__UartTracerStatus__Sequence * input,
  tracer_msgs__msg__UartTracerStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tracer_msgs__msg__UartTracerStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tracer_msgs__msg__UartTracerStatus * data =
      (tracer_msgs__msg__UartTracerStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tracer_msgs__msg__UartTracerStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tracer_msgs__msg__UartTracerStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tracer_msgs__msg__UartTracerStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
