#include "MiniTrip.h"

MiniTrip::MiniTrip(int tripCode, string start, string end, float distance)
    : Trip(tripCode, start, end, distance) {
}

float MiniTrip::computeCost() {
    return 40 + distance * 9;
}

void MiniTrip::display() {
    cout << "Category: Mini Transport" << endl;
    Trip::display();
    cout << "Total Cost: " << computeCost() << endl;
}