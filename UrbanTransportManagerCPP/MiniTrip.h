#ifndef MINITRIP_H
#define MINITRIP_H

#include "Trip.h"

class MiniTrip : public Trip {
public:
    MiniTrip(int tripCode, string start, string end, float distance);
    float computeCost();
    void display();
};

#endif