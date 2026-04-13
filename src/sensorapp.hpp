#pragma once
#include "sensor.hpp"
#include "hashTable.hpp"
#include <memory>

using namespace std;

enum class TableMode { CHAINING, OPEN_ADDRESSING };

class SensorApp {
private:
    std::shared_ptr<HashTable<Sensor>> table;
public:
    SensorApp(TableMode mode = TableMode::CHAINING);
    void registerSensor();
    void updateReading();
    void searchSensor();
    void removeSensor();
    void displaySensors();
};
