#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

class AGVRobotInfo : public RobotInfo {
private:
  int maximum_payload;

public:
  AGVRobotInfo(std::string desc, std::string serial, std::string ip,
               std::string firmware, int payload);

  virtual ~AGVRobotInfo();

  virtual void publish_data() override;
};

#endif // AGV_ROBOT_INFO_CLASS_H
