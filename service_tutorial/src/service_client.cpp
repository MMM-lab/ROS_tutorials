#include "ros/ros.h"
#include "service_tutorial/Srvtutorial.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "service_client");

    if (argc != 3) {
        ROS_INFO("Error!!!");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<service_tutorial::Srvtutorial>("ros_srv");

    service_tutorial::Srvtutorial srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if (client.call(srv)) {
        ROS_INFO("%ld", (long int)srv.response.result);
    } else {
        ROS_INFO("Error!!");
        return 1;
    }

    return 0;
}

