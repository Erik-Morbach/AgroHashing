#pragma once
#include "hashable.hpp"
#include <string>

#define PRIMO 1000000007LL

using namespace std;

class Sensor: public Hashable<Sensor> {
private:
    int iId;
    string strType;
    string strLocation;
    double dLastReading;

public:
    Sensor();
    Sensor(const Sensor &oth);
    Sensor(int iIdParam, string strTypeParam, string strLocationParam);

    void setReading(double dReading);
    int getId() const;
    void print() const;
    virtual unsigned long long int hash() const;
    bool operator==(const Sensor &oth) const;
    string str() const;
};