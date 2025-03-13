#include "robot_info/robot_info_class.h"
#include "ros/init.h"
#include "ros/rate.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");

  RobotInfo r("Aster", "567A359", "10.10.10.110", "1.0.3");
  ros::Rate rate(1);
  while (ros::ok()) {
    r.publish_data();
    ros::spinOnce();
    rate.sleep();
  }
  return 0;
}