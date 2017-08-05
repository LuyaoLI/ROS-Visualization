#include "LidarPose.h"


int main(int argc, char** argv){

       ros::init(argc, argv, "tf_listener");
       ros::NodeHandle nh;
       LidarPose lidar_pose = LidarPose(nh);   
   
       tf::TransformListener listener;
       tf::StampedTransform transform;
   
       ros::Rate rate(1);
       while (nh.ok()){
	       
	       try{
		 listener.lookupTransform("/map", "/velodyne",
		                          ros::Time(0), transform);
	       }
	       catch (tf::TransformException &ex) {
		 ROS_ERROR("%s",ex.what());
		 ros::Duration(1.0).sleep();
		 continue;
       }

       lidar_pose.publish(lidar_pose.getPoseMsgByTransform(transform));

       ROS_INFO("Message publish: Real Pose!!!");
   
       rate.sleep();
     }
     return 0;

}
