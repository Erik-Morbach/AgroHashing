#include "sensorapp.hpp"
#include <iostream>
#include "linkedHashTable.hpp"
    
SensorApp::SensorApp() {
    this->table = std::make_shared<LinkedHashTable<Sensor, 100>>();
}
void SensorApp::registerSensor() {
    int iId;
    string strType, strLocation;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    cout << "Enter Sensor Type: ";
    cin >> strType;
    cout << "Enter Sensor Location: ";
    cin >> strLocation;
    Sensor s(iId, strType, strLocation);
    this->table->add(s);
    
}

void SensorApp::updateReading() {
    int iId;
    double dReading;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    cout << "Enter new reading: ";
    cin >> dReading;
    cout << "Reading updated!" << endl;
    std::shared_ptr<Sensor> s = this->table->search(Sensor(iId, "", ""));
    if(s) s->setReading(dReading);
    else cout << "Sensor not found" << endl;
}

void SensorApp::searchSensor() {
    int iId;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    std::shared_ptr<Sensor> s = this->table->search(Sensor(iId, "", ""));
    if(!s) cout << "Sensor not found" << endl;
    else cout << "Found sensor: " << s->str() << endl;
}

void SensorApp::removeSensor() {
    int iId;
    cout << "Enter Sensor ID: ";
    cin >> iId;
    if(this->table->remove(Sensor(iId, "", ""))) cout << "Sensor remove correctly" << endl;
    else cout << "Sensor not found" << endl;
}

void SensorApp::displaySensors() {
    cout << "List of registred sensors: ";
    for(auto sensor : this->table->listAll()) {
        sensor->print();
    }

}