#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/PoseStamped.h"
#include "pub_subs/Detection.h"

#include <sstream>


int main(int argc, char **argv){
    ros::init(argc, argv, "tag_pose");
    ros::init(argc, argv, "image_color");
    ros::init(argc, argv, "tag_detection");

    ros::NodeHandle n;
    ros::Publisher tag_pose = n.advertise<geometry_msgs::PoseStamped>("tag_pose", 1000);
    ros::Publisher image_color = n.advertise<sensor_msgs::Image>("image_color", 1000);
    ros::Publisher tag_detection = n.advertise<pub_subs::Detection>("tag_detection", 1000);

    ros::Rate loop_rate(1);
    while(ros::ok()){
        geometry_msgs::PoseStamped msg;
 
	msg.header.frame_id = "camera";
	msg.header.stamp = ros::Time::now();
	msg.pose.position.x = 0.0;
	msg.pose.position.y = 0.0;
	msg.pose.position.z = 0.0;

	msg.pose.orientation.x = 0.0;
	msg.pose.orientation.y = 0.0;
	msg.pose.orientation.z = 0.0;
	msg.pose.orientation.w = 1.0;
        
	ROS_INFO("Message publish: Pose");

	tag_pose.publish(msg);
      


	sensor_msgs::Image msg2;
	msg.header.frame_id = "camera";
	msg.header.stamp = ros::Time::now();
	//msg.height = 2;
	//msg.width = 1;
	//msg.encoding = "UTF-8";

	//msg.is_bigendian = false;
	//msg.step = 200;
	//msg.data = {(0,0,0),(1,1,1)};
	
	
	ROS_INFO("Message publish: Image");

	image_color.publish(msg2);
        


        pub_subs::Detection msg3;

	msg3.tag_id = 6;
	msg3.cam_id = 6;
	msg3.pixel = {0.1, 0.2, 0.3};

        ROS_INFO("Message publish: Detection");

	tag_detection.publish(msg3);

	ros::spinOnce();

	loop_rate.sleep();


    }
    
    return 0;
}
