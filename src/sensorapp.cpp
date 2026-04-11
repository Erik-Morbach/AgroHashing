#include "sensorapp.h"
#include <iostream>
    
void SensorApp::registerSensor() {
    int iId;
    string strType, strLocation;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    cout << "Enter Sensor Type: ";
    cin >> strType;
    cout << "Enter Sensor Location: ";
    cin >> strLocation;
    cout << "Sensor registered successfully!" << endl;
}

void SensorApp::updateReading() {
    int iId;
    double dReading;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    cout << "Enter new reading: ";
    cin >> dReading;
    cout << "Reading updated!" << endl;
}

void SensorApp::searchSensor() {
    int iId;
    cout << "Enter Sensor ID: ";
    cin >> iId;
}

void SensorApp::removeSensor() {
    int iId;
    cout << "Enter Sensor ID: ";
    cin >> iId;
}

void SensorApp::displaySensors() {
    cout << "List of registred sensors: ";
    for(Sensor sensor : this->sensors) {
        sensor.print();
    }

}