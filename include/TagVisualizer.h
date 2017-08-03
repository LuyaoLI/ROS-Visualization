#ifndef TagVisualizer_H_
#define TagVisualizer_H_

#include "ros/ros.h"
#include "sensor_msgs/Image.h"
#include "geometry_msgs/PoseStamped.h"
#include "pub_subs/Detection.h"

class TagVisualizer{

public:

       	ros::Subscriber image_sub;
	ros::Subscriber pose_sub;
	ros::Subscriber detection_sub;

	TagVisualizer();
	TagVisualizer(ros::NodeHandle nh);

	// void image_callback(const sensor_msgs::Image::ConstPtr& msg);
	void image_callback(const sensor_msgs::Image& msg);

	void pose_callback(const geometry_msgs::PoseStamped& msg);

	void detection_callback(const pub_subs::Detection& msg);

	~TagVisualizer();


};


#endif
