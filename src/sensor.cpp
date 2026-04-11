#include "sensor.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Sensor::Sensor() {
    this->iId = 0;
    this->strType = "";
    this->strLocation = "";
    this->dLastReading = 0.0;
}
Sensor::Sensor(const Sensor &oth) {
    this->iId = oth.iId;
    this->strType = oth.strType;
    this->strLocation = oth.strLocation;
    this->dLastReading = oth.dLastReading;
}

Sensor::Sensor(int iIdParam, string strTypeParam, string strLocationParam) {
    this->iId = iIdParam;
    this->strType = strTypeParam;
    this->strLocation = strLocationParam;
    this->dLastReading = 0.0;
}
   
void Sensor::setReading(double dReading) {
    this->dLastReading = dReading;
}

int Sensor::getId() const {
    return this->iId;
}

void Sensor::print() const {
    cout << "-------------------------" << endl;
    cout << "ID: " << this->iId << endl;
    cout << "Type: " << this->strType << endl;
    cout << "Location: " << this->strLocation << endl;
    cout << "Last Reading: " << this->dLastReading << endl;
    cout << "-------------------------" << endl;
}

unsigned long long int Sensor::hash() const{
    return this->iId;
}

bool Sensor::operator==(const Sensor &oth) const {
    return this->iId == oth.iId;
}
string Sensor::str() const {
    ostringstream ss;
    ss << "ID: " << this->iId << endl;
    ss << "Type: " << this->strType << endl;
    ss << "Location: " << this->strLocation << endl;
    ss << "Last Reading: " << this->dLastReading << endl;
    return ss.str();
}