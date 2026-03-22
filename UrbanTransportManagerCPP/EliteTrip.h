#ifndef ELITETRIP_H
#define ELITETRIP_H

#include "Trip.h"

class EliteTrip : public Trip {
private:
    float comfortFee;

public:
    EliteTrip(int tripCode, string start, string end, float distance, float comfortFee);
    float computeCost();
    void display();
};

#endif