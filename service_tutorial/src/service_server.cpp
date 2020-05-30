#include "ros/ros.h"
#include "service_tutorial/Srvtutorial.h"

bool calculation(service_tutorial::Srvtutorial::Request  &req,
                 service_tutorial::Srvtutorial::Response &res)
{
    res.result = req.a + req.b;

    ROS_INFO("%ld, %ld", (long int)req.a, (long int)req.b);
    ROS_INFO("%ld", (long int)res.result);

    return true;
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "service_server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("ros_srv", calculation);
    ROS_INFO("ready srv server!");

    ros::spin();

    return 0;
}
