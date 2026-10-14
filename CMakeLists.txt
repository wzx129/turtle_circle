cmake_minimum_required(VERSION 3.0.2)
project(turtle_circle)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_circle_node src/turtle_circle_node.cpp)
target_link_libraries(turtle_circle_node ${catkin_LIBRARIES})
