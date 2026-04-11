#pragma once
#include "sensor.hpp"
#include "hashTable.hpp"
#include <memory>

using namespace std;

class SensorApp {
private:
    std::shared_ptr<HashTable<Sensor>> table;
public:
    SensorApp();
    void registerSensor();
    void updateReading();
    void searchSensor();
    void removeSensor();
    void displaySensors();
};