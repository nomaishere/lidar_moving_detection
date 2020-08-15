cmake_minimum_required(VERSION 2.8.3)
project(lidar_moving_detection)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs sensor_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Num.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs sensor_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(rpscan_listener src/scripts/rpscan_listener.cpp)
target_link_libraries(rpscan_listener ${catkin_LIBRARIES})
add_dependencies(rpscan_listener lidar_moving_detection_generate_messages_cpp)

add_executable(point_detector src/scripts/point_detector.cpp)
target_link_libraries(point_detector ${catkin_LIBRARIES})
add_dependencies(point_detector lidar_moving_detection_generate_messages_cpp)