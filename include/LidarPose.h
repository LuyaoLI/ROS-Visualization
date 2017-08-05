#ifndef LidarPose_H_
#define LidarPose_H_

#include "ros/ros.h"
#include <tf/transform_listener.h>
#include "geometry_msgs/PoseStamped.h"

class LidarPose{

public:

        ros::Publisher lidar_pose;

	LidarPose();
	LidarPose(ros::NodeHandle nh);

	geometry_msgs::PoseStamped* getPoseMsgByTransform(tf::StampedTransform transform);
	void publish(geometry_msgs::PoseStamped* pose_msg);

	~LidarPose();


};


#endif
