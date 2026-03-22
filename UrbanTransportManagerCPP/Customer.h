#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include "Trip.h"
using namespace std;

class Customer {
private:
    string customerName;
    vector<Trip*> bookedTrips;

public:
    Customer(string customerName);

    void bookTrip(Trip* t);
    void showBookings();
};

#endif