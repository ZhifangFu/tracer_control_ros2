// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tracer_msgs:msg/TracerMotorState.idl
// generated code does not contain a copyright notice
#include "tracer_msgs/msg/detail/tracer_motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
tracer_msgs__msg__TracerMotorState__init(tracer_msgs__msg__TracerMotorState * msg)
{
  if (!msg) {
    return false;
  }
  // rpm
  return true;
}

void
tracer_msgs__msg__TracerMotorState__fini(tracer_msgs__msg__TracerMotorState * msg)
{
  if (!msg) {
    return;
  }
  // rpm
}

bool
tracer_msgs__msg__TracerMotorState__are_equal(const tracer_msgs__msg__TracerMotorState * lhs, const tracer_msgs__msg__TracerMotorState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rpm
  if (lhs->rpm != rhs->rpm) {
    return false;
  }
  return true;
}

bool
tracer_msgs__msg__TracerMotorState__copy(
  const tracer_msgs__msg__TracerMotorState * input,
  tracer_msgs__msg__TracerMotorState * output)
{
  if (!input || !output) {
    return false;
  }
  // rpm
  output->rpm = input->rpm;
  return true;
}

tracer_msgs__msg__TracerMotorState *
tracer_msgs__msg__TracerMotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__TracerMotorState * msg = (tracer_msgs__msg__TracerMotorState *)allocator.allocate(sizeof(tracer_msgs__msg__TracerMotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tracer_msgs__msg__TracerMotorState));
  bool success = tracer_msgs__msg__TracerMotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tracer_msgs__msg__TracerMotorState__destroy(tracer_msgs__msg__TracerMotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tracer_msgs__msg__TracerMotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tracer_msgs__msg__TracerMotorState__Sequence__init(tracer_msgs__msg__TracerMotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__TracerMotorState * data = NULL;

  if (size) {
    data = (tracer_msgs__msg__TracerMotorState *)allocator.zero_allocate(size, sizeof(tracer_msgs__msg__TracerMotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tracer_msgs__msg__TracerMotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tracer_msgs__msg__TracerMotorState__fini(&data[i - 1]);
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
tracer_msgs__msg__TracerMotorState__Sequence__fini(tracer_msgs__msg__TracerMotorState__Sequence * array)
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
      tracer_msgs__msg__TracerMotorState__fini(&array->data[i]);
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

tracer_msgs__msg__TracerMotorState__Sequence *
tracer_msgs__msg__TracerMotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tracer_msgs__msg__TracerMotorState__Sequence * array = (tracer_msgs__msg__TracerMotorState__Sequence *)allocator.allocate(sizeof(tracer_msgs__msg__TracerMotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tracer_msgs__msg__TracerMotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tracer_msgs__msg__TracerMotorState__Sequence__destroy(tracer_msgs__msg__TracerMotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tracer_msgs__msg__TracerMotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tracer_msgs__msg__TracerMotorState__Sequence__are_equal(const tracer_msgs__msg__TracerMotorState__Sequence * lhs, const tracer_msgs__msg__TracerMotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tracer_msgs__msg__TracerMotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tracer_msgs__msg__TracerMotorState__Sequence__copy(
  const tracer_msgs__msg__TracerMotorState__Sequence * input,
  tracer_msgs__msg__TracerMotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tracer_msgs__msg__TracerMotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tracer_msgs__msg__TracerMotorState * data =
      (tracer_msgs__msg__TracerMotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tracer_msgs__msg__TracerMotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tracer_msgs__msg__TracerMotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tracer_msgs__msg__TracerMotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
