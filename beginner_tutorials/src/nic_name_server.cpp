#include "ros/ros.h"
#include "beginner_tutorials/NicName.h"

bool add(beginner_tutorials::NicName::Request  &req,
         beginner_tutorials::NicName::Response &res)
{
  res.nic_name = "TaiyaMen";
  ROS_INFO("name: %s", req.name.c_str());
  ROS_INFO("nic name: [%s]", res.nic_name.c_str());
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "nic_name_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("nic_name", add);
  ROS_INFO("Ready to nic name.");
  ros::spin();

  return 0;
}