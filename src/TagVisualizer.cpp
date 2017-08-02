#include "TagVisualizer.h"


void TagVisualizer::image_callback(const sensor_msgs::Image& msg){
    ROS_INFO("Image Received!");
}

void TagVisualizer::pose_callback(const geometry_msgs::PoseStamped& msg){
    ROS_INFO("Pose Received!");
}

void TagVisualizer::detection_callback(const pub_subs::Detection& msg){
    ROS_INFO("Detection Received!");
}

