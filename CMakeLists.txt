cmake_minimum_required(VERSION 2.8.3)
project(pub_subs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  message_generation
)

## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   Detection.msg
   DetectionArray.msg
 )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

 generate_messages(
   DEPENDENCIES
   std_msgs
   sensor_msgs
   geometry_msgs
   pub_subs
 )


catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs geometry_msgs
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

 add_library(TagVisualizer
   src/TagVisualizer.cpp
 )
 target_link_libraries(TagVisualizer
   ${catkin_LIBRARIES}
 )


 add_executable(publisher src/publisher.cpp)

 target_link_libraries(publisher
   ${catkin_LIBRARIES}
 )
 add_dependencies(publisher 
 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
# pub_subs_generate_messages_cpp
 )



 add_executable(TagVisualizerNode src/TagVisualizerNode.cpp)
 target_link_libraries(TagVisualizerNode TagVisualizer
   ${catkin_LIBRARIES}
 )
 add_dependencies(TagVisualizerNode
  ${catkin_EXPORTED_TARGETS}
# pub_subs_generate_messages_cpp
 )


