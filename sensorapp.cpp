#include "sensorapp.h"
#include <iostream>

class SensorApp {
private:
    Sensor sensors[NUM_MAX_SENSORS];
    int numSensors;

public:

    SensorApp() {
        numSensors = 0;
    }
    
    void registerSensor() {
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

    void updateReading() {
        int iId;
        double dReading;

        cout << "Enter Sensor ID: ";
        cin >> iId;


        cout << "Enter new reading: ";
        cin >> dReading;

        cout << "Reading updated!" << endl;
    }

    void searchSensor() {
        int iId;

        cout << "Enter Sensor ID: ";
        cin >> iId;

    }


    void removeSensor() {
        int iId;

        cout << "Enter Sensor ID: ";
        cin >> iId;

    }

    void displaySensors() {
        cout << "List of registred sensors: ";
        for(Sensor sensor : sensors) {
            sensor.print();
        }

    }
};