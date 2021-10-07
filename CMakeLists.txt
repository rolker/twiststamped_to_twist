cmake_minimum_required(VERSION 2.8.3)
project(twiststamped_to_twist)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES twiststamped_to_twist
   CATKIN_DEPENDS geometry_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

 add_executable(${PROJECT_NAME}_node src/twiststamped_to_twist_node.cpp)
 add_executable(twist_to_twiststamped_node src/twist_to_twiststamped_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
 )

target_link_libraries(twist_to_twiststamped_node
   ${catkin_LIBRARIES}
)
