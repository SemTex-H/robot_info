#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include <ros/ros.h>

class RobotInfo {
protected:
  ros::NodeHandle nh;
  ros::Publisher robot_info_pub;

public:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;


  RobotInfo(std::string desc, std::string serial, std::string ip,
            std::string firmware);
            
  virtual ~RobotInfo(); 

  virtual void publish_data();

};
#endif // ROBOT_INFO_CLASS_H