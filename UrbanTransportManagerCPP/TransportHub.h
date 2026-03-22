#ifndef TRANSPORTHUB_H
#define TRANSPORTHUB_H

#include <iostream>
#include <vector>
#include "MiniTrip.h"
#include "EliteTrip.h"
#include "Operator.h"
#include "Customer.h"
using namespace std;

class TransportHub {
private:
    vector<Trip*> allTrips;
    vector<Operator> allOperators;
    vector<Customer> allCustomers;

public:
    void addOperator();
    void addCustomer();
    void createTrip();
    void assignTripToOperator();
    void assignTripToCustomer();
    void showAllTrips();
    void showAllOperators();
    void showAllCustomers();
    void showCustomerTrips();
    void showOperatorTrips();
    void menu();
};

#endif