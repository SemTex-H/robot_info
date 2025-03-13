#include <ros/ros.h>
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "hydraulic_system_monitor.cpp"
#include <sstream>

class AGVRobotInfo : public RobotInfo {
private:
    double maximum_payload;
    ros::Publisher robot_info_pub;
    HydraulicSystemMonitor hsm;

public:
    AGVRobotInfo(const std::string& name, const std::string& model, const std::string& ip, const std::string& version, double payload, ros::NodeHandle& nh)
        : RobotInfo(name, model, ip, version), maximum_payload(payload), hsm("45", "100", "250") {
        // Initialize publisher
        robot_info_pub = nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
    }

    void publish_data() override {
        robotinfo_msgs::RobotInfo10Fields msg;

        std::string temp, level, pressure;

        hsm.getHydraulicData(temp, level, pressure);

        std::string temp1 = hsm.GetOilTemperature();
        std::string level1 = hsm.GetOilTankLevel();
        std::string pressure1 = hsm.GetOilPressure();

        msg.data_field_01 = "robot_description: " + robot_description;
        msg.data_field_02 = "serial_number: " + serial_number;
        msg.data_field_03 = "ip_address: " + ip_address;
        msg.data_field_04 = "firmware_version: " + firmware_version;
        msg.data_field_05 = "maximum_payload: " + std::to_string(maximum_payload) + " Kg";
        msg.data_field_06 = "hydraulic_oil_temperature: " + temp + "C";
        msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + level + "%";
        msg.data_field_08 = "hydraulic_oil_pressure: " + pressure + " bar";
        
        robot_info_pub.publish(msg);
        // ROS_INFO("[PUBLISHED INFO][%s][%s][%s][%s][%f]", robot_description.c_str(),
        //   serial_number.c_str(), ip_address.c_str(),
        //   firmware_version.c_str(), maximum_payload);
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;
    
    AGVRobotInfo agv_robot("Aster", "567A359", "10.10.10.110", "1.0.3", 50.0, nh);
    
    ros::Rate rate(1); // 1 Hz
    while (ros::ok()) {
        agv_robot.publish_data();
        ros::spinOnce();
        rate.sleep();
    }
    
    return 0;
}
