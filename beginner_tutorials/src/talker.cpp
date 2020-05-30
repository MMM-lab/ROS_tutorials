#include "ros/ros.h"
#include "beginner_tutorials/Num.h"

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;

    ros::Publisher chatter_pub = nh.advertise<beginner_tutorials::Num>("chatter", 100);
    ros::Rate loop_rate(10);

    beginner_tutorials::Num msg;
    int count = 0;
    while (ros::ok()) {
        msg.stamp = ros::Time::now();
        msg.data  = count;

        std::stringstream ss;
        ss << "Hello";
        msg.name = ss.str();

        ROS_INFO("%d", msg.stamp.sec);
        ROS_INFO("%d", msg.data);
        ROS_INFO("%s", msg.name.c_str());

        chatter_pub.publish(msg);

        loop_rate.sleep();

        ++count;
    }

    return 0;
}
