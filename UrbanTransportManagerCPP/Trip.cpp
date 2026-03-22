#include "Trip.h"

Trip::Trip(int tripCode, string start, string end, float distance) {
    this->tripCode = tripCode;
    this->start = start;
    this->end = end;
    this->distance = distance;
}

Trip::~Trip() {}

int Trip::getTripCode() {
    return tripCode;
}

void Trip::display() {
    cout << "Trip Code: " << tripCode << endl;
    cout << "Route: " << start << " -> " << end << endl;
    cout << "KM: " << distance << endl;
}