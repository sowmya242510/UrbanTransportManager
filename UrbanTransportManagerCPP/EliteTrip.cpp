#include "EliteTrip.h"

EliteTrip::EliteTrip(int tripCode, string start, string end, float distance, float comfortFee)
    : Trip(tripCode, start, end, distance) {
    this->comfortFee = comfortFee;
}

float EliteTrip::computeCost() {
    return (distance * 15) + comfortFee + 100;
}

void EliteTrip::display() {
    cout << "Category: Elite Transport" << endl;
    Trip::display();
    cout << "Comfort Fee: " << comfortFee << endl;
    cout << "Total Cost: " << computeCost() << endl;
}