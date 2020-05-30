#include "ros/ros.h"
#include "beginner_tutorials/NicName.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::NicName>("nic_name");
  beginner_tutorials::NicName srv;
  srv.request.name = "toko";
  if (client.call(srv))
  {
    ROS_INFO("your nic name is: %s", srv.response.nic_name.c_str());
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
