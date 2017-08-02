#include "TagVisualizer.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "tagVisualizer");
    ros::NodeHandle n;

    TagVisualizer tagVisualizer;
    ros::Subscriber image_sub = n.subscribe("image_color", 1000, &TagVisualizer::image_callback, &tagVisualizer);
    ros::Subscriber pose_sub = n.subscribe("tag_pose", 1000, &TagVisualizer::pose_callback, &tagVisualizer);
    ros::Subscriber detection_sub = n.subscribe("tag_detection", 1000, &TagVisualizer::detection_callback, &tagVisualizer);
    
    ros::spin();
    return 0;
}
