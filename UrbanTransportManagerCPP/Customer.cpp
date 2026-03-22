#include "Customer.h"

Customer::Customer(string customerName) {
    this->customerName = customerName;
}

void Customer::bookTrip(Trip* t) {
    bookedTrips.push_back(t);
}

void Customer::showBookings() {
    cout << "Customer: " << customerName << endl;

    for (int i = 0; i < bookedTrips.size(); i++) {
        bookedTrips[i]->display();
        cout << "----------------" << endl;
    }
}