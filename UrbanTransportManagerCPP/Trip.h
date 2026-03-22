#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <string>
using namespace std;

class Trip {
protected:
    int tripCode;
    string start;
    string end;
    float distance;

public:
    Trip(int tripCode, string start, string end, float distance);
    virtual ~Trip();

    int getTripCode();
    virtual float computeCost() = 0;
    virtual void display();
};

#endif