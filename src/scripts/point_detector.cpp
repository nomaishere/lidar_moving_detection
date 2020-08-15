#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "typeinfo"

#define RAD_TO_DEG(x) ((x)*180./M_PI)

void scannerCallback(const sensor_msgs::LaserScan::ConstPtr& scan) {
    int count = scan->scan_time / scan->time_increment;

    ROS_INFO("%f", scan->ranges[359]);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "point_detector");
    ros::NodeHandle n;
    
    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scannerCallback);
    ros::spin();

    return 0;
}