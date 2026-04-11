#pragma once

#include <string>
using namespace std;

class Sensor {
private:
    int iId;
    string strType;
    string strLocation;
    double dLastReading;

public:
    Sensor();
    Sensor(int iIdParam, string strTypeParam, string strLocationParam);

    void setReading(double dReading);
    int getId() const;
    void print() const;
};
