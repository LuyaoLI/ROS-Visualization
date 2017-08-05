//#include "Tf_Trans_Pose.h"
#include "ros/ros.h"
#include <tf/transform_listener.h>
#include "geometry_msgs/PoseStamped.h"

int main(int argc, char** argv){

     ros::init(argc, argv, "tf_listener");
     ros::NodeHandle nh;
   
//
//     ros::service::waitForService("spawn");
 //    ros::ServiceClient add_turtle =
  //     node.serviceClient<turtlesim::Spawn>("spawn");
   //  turtlesim::Spawn srv;
    // add_turtle.call(srv);
   

     ros::Publisher lidar_pose =
       nh.advertise<geometry_msgs::PoseStamped>("lidar_pose", 1000);

       geometry_msgs::PoseStamped pose_msg;
   
     tf::TransformListener listener;
   
     ros::Rate rate(10.0);
     while (nh.ok()){
       tf::StampedTransform transform;
       try{
         listener.lookupTransform("/map", "/velodyne",
                                  ros::Time(0), transform);
       }
       catch (tf::TransformException &ex) {
         ROS_ERROR("%s",ex.what());
         ros::Duration(1.0).sleep();
         continue;
       }
   
       

       pose_msg.header.frame_id = "lidar";
       pose_msg.header.stamp = ros::Time::now();
	
//API Modified

       pose_msg.pose.position.x = transform.getOrigin().x();
       pose_msg.pose.position.y = transform.getOrigin().y();
       pose_msg.pose.position.z = transform.getOrigin().x();

       pose_msg.pose.orientation.x = transform.getOrigin().x();
       pose_msg.pose.orientation.y = transform.getOrigin().y();
       pose_msg.pose.orientation.z = transform.getOrigin().x();
       pose_msg.pose.orientation.w = transform.getOrigin().y();

       lidar_pose.publish(pose_msg);
ROS_INFO("Message publish: Image");
   
       rate.sleep();
     }
     return 0;

}
