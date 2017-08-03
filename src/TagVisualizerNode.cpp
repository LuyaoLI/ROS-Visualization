#include "TagVisualizer.h"


int main(int argc, char **argv){
    ros::init(argc, argv, "tagVisualizer");
    ros::NodeHandle nh;

    TagVisualizer TagVisualizer(nh);
    
    ros::spin();
    return 0;
}
