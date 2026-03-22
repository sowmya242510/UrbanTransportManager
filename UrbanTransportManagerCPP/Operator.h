#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <vector>
#include "Trip.h"
using namespace std;

class Operator {
private:
    int operatorId;
    string operatorName;
    vector<Trip*> tripsHandled;

public:
    Operator(int operatorId, string operatorName);

    int getId();
    void assignTrip(Trip* t);
    void showInfo();
};

#endif