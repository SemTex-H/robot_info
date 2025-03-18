#include <iostream>
#include <ros/ros.h>
class HydraulicSystemMonitor {
private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;

public:
  HydraulicSystemMonitor(std::string temp, std::string level,
                         std::string pressure)
      : hydraulic_oil_temperature(temp), hydraulic_oil_tank_fill_level(level),
        hydraulic_oil_pressure(pressure) {}

  std::string GetOilTemperature() const { return hydraulic_oil_temperature; }
  std::string GetOilTankLevel() const { return hydraulic_oil_tank_fill_level; }
  std::string GetOilPressure() const { return hydraulic_oil_pressure; }

  void getHydraulicData(std::string &temp, std::string &level,
                        std::string &pressure) const {
    temp = hydraulic_oil_temperature;
    level = hydraulic_oil_tank_fill_level;
    pressure = hydraulic_oil_pressure;
  }
};