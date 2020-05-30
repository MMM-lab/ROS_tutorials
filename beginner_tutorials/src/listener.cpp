#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

void callback(const beginner_tutorials::Num::ConstPtr& msg) {
    ROS_INFO("%d", msg->stamp.sec);
    ROS_INFO("%d", msg->data);
    ROS_INFO("%s", msg->name.c_str());
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 100, callback);
    ros::spin();

    return 0;
}
