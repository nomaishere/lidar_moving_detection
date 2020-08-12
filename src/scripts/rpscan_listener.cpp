#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"

void scannerCallback(const sensor_msgs::LaserScan::ConstPtr msg) {
    ROS_INFO("I heard: [%s]", msg->ranges);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "rpscan_listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/scan", 1000, scannerCallback);
    ros::spin();

    return 0;
}