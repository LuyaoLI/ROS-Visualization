#include "TagVisualizer.h"


TagVisualizer::TagVisualizer(){

}

TagVisualizer::TagVisualizer(ros::NodeHandle nh){
    image_sub = nh.subscribe("camera/image_mono", 1000, &TagVisualizer::image_callback, this);
    pose_sub = nh.subscribe("tag_pose", 1000, &TagVisualizer::pose_callback, this);
    detection_sub = nh.subscribe("tag_detection", 1000, &TagVisualizer::detection_callback, this);
}

void TagVisualizer::image_callback(const sensor_msgs::Image& msg){
    ROS_INFO("Image Received!");
}

void TagVisualizer::pose_callback(const geometry_msgs::PoseStamped& msg){
    ROS_INFO("Pose Received!");
}

void TagVisualizer::detection_callback(const pub_subs::Detection& msg){
    ROS_INFO("Detection Received!");
}

TagVisualizer::~TagVisualizer(){
}
