#include "ros/ros.h"
#include "beginner_tutorials/NicName.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 2)
  {
    ROS_INFO("only one please");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::NicName>("nic_name");
  beginner_tutorials::NicName srv;
  srv.request.name = argv[1];
  if (client.call(srv))
  {
    ROS_INFO("your name is: %s", argv[1]);
    ROS_INFO("your nic name is: %s", srv.response.nic_name.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
