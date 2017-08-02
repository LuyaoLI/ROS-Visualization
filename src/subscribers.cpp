#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/PoseStamped.h"
#include "pub_subs/Detection.h"


// void image_callback(const sensor_msgs::Image::ConstPtr& msg){
void image_callback(const sensor_msgs::Image& msg){
    ROS_INFO("Image Received!");
}

void pose_callback(const geometry_msgs::PoseStamped& msg){
    ROS_INFO("Pose Received!");
}

void detection_callback(const pub_subs::Detection& msg){
    ROS_INFO("Detection Received!");
}


int main(int argc, char **argv){
    ros::init(argc, argv, "subscribers");

    ros::NodeHandle n;
    ros::Subscriber image_sub = n.subscribe("image_color", 1000, image_callback);
    ros::Subscriber pose_sub = n.subscribe("tag_pose", 1000, pose_callback);
    ros::Subscriber detection_sub = n.subscribe("tag_detection", 1000, detection_callback);

    ros::spin();
    return 0;
}
