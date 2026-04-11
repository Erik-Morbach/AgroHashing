#ifndef SENSORAPP_H
#define SENSORAPP_H

#include "sensor.h"

using namespace std;

#define NUM_MAX_SENSORS 10

class SensorApp {
private:
    Sensor sensors[NUM_MAX_SENSORS];

public:
    void registerSensor();
    void updateReading();
    void searchSensor();
    void removeSensor();
    void displaySensors();
};

#endif