#include "LidarPose.h"


LidarPose::LidarPose(){
}

LidarPose::LidarPose(ros::NodeHandle nh){
     lidar_pose = nh.advertise<geometry_msgs::PoseStamped>("lidar_pose", 1000);
}

geometry_msgs::PoseStamped* LidarPose::getPoseMsgByTransform(tf::StampedTransform transform){
       geometry_msgs::PoseStamped pose_msg;
    
       pose_msg.header.frame_id = "lidar";
       pose_msg.header.stamp = ros::Time::now();
	
	//API To Be Modified
       pose_msg.pose.position.x = transform.getOrigin().x();
       pose_msg.pose.position.y = transform.getOrigin().y();
       pose_msg.pose.position.z = transform.getOrigin().x();

       pose_msg.pose.orientation.x = transform.getOrigin().x();
       pose_msg.pose.orientation.y = transform.getOrigin().y();
       pose_msg.pose.orientation.z = transform.getOrigin().x();
       pose_msg.pose.orientation.w = transform.getOrigin().y();

       return &pose_msg;
}

void LidarPose::publish(geometry_msgs::PoseStamped* pose_msg){
     lidar_pose.publish(*pose_msg);
}

LidarPose::~LidarPose(){
}
