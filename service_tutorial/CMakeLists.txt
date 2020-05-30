cmake_minimum_required(VERSION 3.0.2)
project(service_tutorial)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

add_service_files(
    FILES
    Srvtutorial.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  LIBRARIES service_tutorial
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)

###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(service_server src/service_server.cpp)
target_link_libraries(service_server ${catkin_LIBRARIES})
add_dependencies(service_server service_tutorial_gencpp)

add_executable(service_tutorial src/service_tutorial.cpp)
target_link_libraries(service_tutorial ${catkin_LIBRARIES})
add_dependencies(service_tutorial service_tutorial_gencpp)
