cmake_minimum_required(VERSION 3.8)
project(tracer_msgs)

# Set compiler options
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

# Message definitions
set(msg_files
  "msg/TracerMotorState.msg"
  "msg/UartTracerMotorState.msg"
  "msg/TracerLightState.msg"
  "msg/TracerLightCmd.msg"
  "msg/TracerStatus.msg"
  "msg/UartTracerStatus.msg"
)

# Generate interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  DEPENDENCIES std_msgs
)

# 移除以下安装指令，因为它试图安装不存在的 include 目录
# install(
#   DIRECTORY include/
#   DESTINATION include
# )

# 仅安装 msg 文件（可选，但建议）
install(
  DIRECTORY msg/
  DESTINATION share/${PROJECT_NAME}/msg
)

# Export dependencies
ament_export_dependencies(rosidl_default_runtime)
ament_export_dependencies(std_msgs)
# ament_export_include_directories(include)  # 如果有自定义头文件时才需要

ament_package()