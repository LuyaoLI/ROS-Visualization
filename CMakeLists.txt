cmake_minimum_required(VERSION 2.8.3)
project(pub_subs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  geometry_msgs
  tf
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
   tf
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


 add_library(LidarPose
   src/LidarPose.cpp
 )
 target_link_libraries(LidarPose
   ${catkin_LIBRARIES}
 )


 add_executable(publisher src/publisher.cpp)

 target_link_libraries(publisher
   ${catkin_LIBRARIES}
 )
 add_dependencies(publisher 
 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
 )



 add_executable(TagVisualizerNode src/TagVisualizerNode.cpp)
 target_link_libraries(TagVisualizerNode TagVisualizer
   ${catkin_LIBRARIES}
 )
 add_dependencies(TagVisualizerNode
  ${catkin_EXPORTED_TARGETS}
 )


 add_executable(LidarPoseNode src/LidarPoseNode.cpp)
 target_link_libraries(LidarPoseNode LidarPose
 ${catkin_LIBRARIES}
 )
  add_dependencies(LidarPoseNode
  ${catkin_EXPORTED_TARGETS}
 )


