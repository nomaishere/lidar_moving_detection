#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include "typeinfo"
#include <vector>

#define RAD_TO_DEG(x) ((x)*180. / M_PI)

/*
class PointStorage
{
private:
    std::vector<std::vector<float>> pointVector;

public:
    bool isStorageFill()
    {
        std::vector<std::vector<float>>::iterator itor = pointVector.begin();
        for (; itor != pointVector.end(); itor++)
            ROS_INFO("%f", *itor);

        return true;
    }
    void printTest(sensor_msgs::LaserScan::Ptr &scan)
    {
        pointVector.push_back(scan->ranges);
        ROS_INFO("%f %d", pointVector.back(), pointVector.size);
    }
};

void movingDetector()
{
}

*/

std::vector<std::vector<float>> tempPoint(0);
bool isStart = false;

void scannerCallback(const sensor_msgs::LaserScan::ConstPtr &scan)
{
    /*
    if (abs(tempPoint.back()[120] - scan->ranges[120]) >= 10)
    {
        ROS_INFO("Detected");
    }*/
    if (isStart == false)
    {
        tempPoint.push_back(scan->ranges);
        ROS_INFO("init");
        isStart = true;
    }
    else
    {
        if (abs(tempPoint.back()[120] - scan->ranges[120]) > 0.02)
            ROS_INFO("detected : %f", abs(tempPoint.back()[120] - scan->ranges[120]));
        tempPoint.push_back(scan->ranges);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_detector");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe<sensor_msgs::LaserScan>("/scan", 1000, scannerCallback);
    ros::spin();

    return 0;
}