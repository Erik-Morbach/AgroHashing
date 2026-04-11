#include "sensor.h"
#include <iostream>

using namespace std;

class Sensor {
private:
    int iId;
    string strType;
    string strLocation;
    double dLastReading;

public:
    Sensor() {
        iId = 0;
        strType = "";
        strLocation = "";
        dLastReading = 0.0;
    }

    Sensor(int iIdParam, string strTypeParam, string strLocationParam) {
        iId = iIdParam;
        strType = strTypeParam;
        strLocation = strLocationParam;
        dLastReading = 0.0;
    }
   
    void setReading(double dReading) {
        dLastReading = dReading;
    }

    int getId() const { return iId; }

    void print() const {
        cout << "-------------------------" << endl;
        cout << "ID: " << iId << endl;
        cout << "Type: " << strType << endl;
        cout << "Location: " << strLocation << endl;
        cout << "Last Reading: " << dLastReading << endl;
        cout << "-------------------------" << endl;
    }
};