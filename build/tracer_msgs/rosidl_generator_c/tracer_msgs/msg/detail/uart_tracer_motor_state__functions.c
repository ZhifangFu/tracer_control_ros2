// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tracer_msgs:msg/UartTracerMotorState.idl
// generated code does not contain a copyright notice
#include "tracer_msgs/msg/detail/uart_tracer_motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tracer_msgs__msg__UartTracerMotorState__init(tracer_msgs__msg__UartTracerMotorState * msg)
{
  if (!msg) {
    return false;
  }
  // current
  // rpm
  // temperature
  return true;
}

void
tracer_msgs__msg__UartTracerMotorState__fini(tracer_msgs__msg__UartTracerMotorState * msg)
{
  if (!msg) {
    return;
  }
  // current
  // rpm
  // temperature
}

bool
tracer_msgs__msg__UartTracerMotorState__are_equal(const tracer_msgs__msg__UartTracerMotorState * lhs, const tracer_msgs__msg__UartTracerMotorState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // rpm
  if (lhs->rpm != rhs->rpm) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  return true;
}

bool
tracer_msgs__msg__UartTracerMotorState__copy(
  const tracer_msgs__msg__UartTracerMotorState * input,
  tracer_msgs__msg__UartTracerMotorState * output)
{
  if (!input || !output) {
    return false;
  }
  // current
  output->current = input->current;
  // rpm
  output->rpm = input->rpm;
  // temperature
  output->temperature = input->temperature;
  return true;
}

tracer_msgs__msg__UartTracerMotorState *
tracer_msgs__msg__UartTracerMotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerMotorState * msg = (tracer_msgs__msg__UartTracerMotorState *)allocator.allocate(sizeof(tracer_msgs__msg__UartTracerMotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tracer_msgs__msg__UartTracerMotorState));
  bool success = tracer_msgs__msg__UartTracerMotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tracer_msgs__msg__UartTracerMotorState__destroy(tracer_msgs__msg__UartTracerMotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tracer_msgs__msg__UartTracerMotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tracer_msgs__msg__UartTracerMotorState__Sequence__init(tracer_msgs__msg__UartTracerMotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerMotorState * data = NULL;

  if (size) {
    data = (tracer_msgs__msg__UartTracerMotorState *)allocator.zero_allocate(size, sizeof(tracer_msgs__msg__UartTracerMotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tracer_msgs__msg__UartTracerMotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tracer_msgs__msg__UartTracerMotorState__fini(&data[i - 1]);
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
tracer_msgs__msg__UartTracerMotorState__Sequence__fini(tracer_msgs__msg__UartTracerMotorState__Sequence * array)
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
      tracer_msgs__msg__UartTracerMotorState__fini(&array->data[i]);
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

tracer_msgs__msg__UartTracerMotorState__Sequence *
tracer_msgs__msg__UartTracerMotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__UartTracerMotorState__Sequence * array = (tracer_msgs__msg__UartTracerMotorState__Sequence *)allocator.allocate(sizeof(tracer_msgs__msg__UartTracerMotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tracer_msgs__msg__UartTracerMotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tracer_msgs__msg__UartTracerMotorState__Sequence__destroy(tracer_msgs__msg__UartTracerMotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tracer_msgs__msg__UartTracerMotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tracer_msgs__msg__UartTracerMotorState__Sequence__are_equal(const tracer_msgs__msg__UartTracerMotorState__Sequence * lhs, const tracer_msgs__msg__UartTracerMotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tracer_msgs__msg__UartTracerMotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tracer_msgs__msg__UartTracerMotorState__Sequence__copy(
  const tracer_msgs__msg__UartTracerMotorState__Sequence * input,
  tracer_msgs__msg__UartTracerMotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tracer_msgs__msg__UartTracerMotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tracer_msgs__msg__UartTracerMotorState * data =
      (tracer_msgs__msg__UartTracerMotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tracer_msgs__msg__UartTracerMotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tracer_msgs__msg__UartTracerMotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tracer_msgs__msg__UartTracerMotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
