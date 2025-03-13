#include "robot_info/agv_robot_info_class.h"
#include "ros/init.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "/agv_robot_info_node");

  AGVRobotInfo agv_r("Aster", "567A359", "10.10.10.110", "1.0.3", 100);
  ros::Rate rate(1);
  while (ros::ok()) {
    agv_r.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}