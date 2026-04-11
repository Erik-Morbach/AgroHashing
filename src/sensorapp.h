#pragma once
#include "sensor.h"
#include <vector>

using namespace std;

class SensorApp {
private:
    vector<Sensor> sensors;
public:
    void registerSensor();
    void updateReading();
    void searchSensor();
    void removeSensor();
    void displaySensors();
};