cmake_minimum_required(VERSION 3.8)
project(tracer_base)

# 设置 C++17 标准
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# 在调试模式下启用符号
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-g)
endif()

# 添加警告选项
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 查找依赖包
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tracer_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(ugv_sdk REQUIRED)

# 创建变量存储 CAN 相关库
set(ALL_CAN_LIBS "")
set(UGV_SDK_LIB ugv_sdk)

# 查找系统级 CAN 支持库
find_library(SOCKETCAN_LIB NAMES socketcan)
if(SOCKETCAN_LIB)
  message(STATUS "Found libsocketcan: ${SOCKETCAN_LIB}")
  list(APPEND ALL_CAN_LIBS ${SOCKETCAN_LIB})
else()
  message(WARNING "libsocketcan not found - CAN support may be limited")
endif()

find_library(PCAN_LIB NAMES pcan)
if(PCAN_LIB)
  message(STATUS "Found libpcan: ${PCAN_LIB}")
  list(APPEND ALL_CAN_LIBS ${PCAN_LIB})
else()
  message(WARNING "libpcan not found - PCAN support disabled")
endif()

# 设置包含目录
include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
  ${tf2_INCLUDE_DIRS}
  ${tf2_ros_INCLUDE_DIRS}
  ${tf2_geometry_msgs_INCLUDE_DIRS}
  ${tracer_msgs_INCLUDE_DIRS}
  ${nav_msgs_INCLUDE_DIRS}
  ${ugv_sdk_INCLUDE_DIRS}
)

# 创建静态库
add_library(tracer_messenger STATIC
  src/tracer_messenger.cpp
)

# 库链接
target_link_libraries(tracer_messenger
  ${rclcpp_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${tf2_LIBRARIES}
  ${tf2_ros_LIBRARIES}
  ${tf2_geometry_msgs_LIBRARIES}
  ${tracer_msgs_LIBRARIES}
  ${nav_msgs_LIBRARIES}
  ${UGV_SDK_LIB}
  ${ALL_CAN_LIBS}
  pthread
  rt
)

# 设置目标属性
set_target_properties(tracer_messenger PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)

# 创建可执行文件
add_executable(tracer_base_node
  src/tracer_base_node.cpp
)

# 可执行文件链接
target_link_libraries(tracer_base_node
  tracer_messenger
  ${rclcpp_LIBRARIES}
  ${sensor_msgs_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${geometry_msgs_LIBRARIES}
  ${tf2_LIBRARIES}
  ${tf2_ros_LIBRARIES}
  ${tf2_geometry_msgs_LIBRARIES}
  ${tracer_msgs_LIBRARIES}
  ${nav_msgs_LIBRARIES}
  ${UGV_SDK_LIB}
  ${ALL_CAN_LIBS}
  pthread
  rt
)

# 安装规则
install(TARGETS tracer_base_node
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS tracer_messenger
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

install(DIRECTORY include/
  DESTINATION include
)

# 修复：安全安装目录，只安装存在的目录
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/launch)
  install(
    DIRECTORY
      launch
    DESTINATION share/${PROJECT_NAME}
  )
else()
  message(WARNING "launch directory not found, skipping")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/urdf)
  install(
    DIRECTORY
      urdf
    DESTINATION share/${PROJECT_NAME}
  )
else()
  message(WARNING "urdf directory not found, skipping")
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/config)
  install(
    DIRECTORY
      config
    DESTINATION share/${PROJECT_NAME}
  )
else()
  message(WARNING "config directory not found, skipping")
endif()

# 添加测试
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# 导出目标
ament_export_include_directories(include)
ament_export_libraries(tracer_messenger)
ament_export_dependencies(
  rclcpp
  sensor_msgs
  std_msgs
  geometry_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  tracer_msgs
  nav_msgs
  ugv_sdk
)

# 生成包配置
ament_package()