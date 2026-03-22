#include "Operator.h"

Operator::Operator(int operatorId, string operatorName) {
    this->operatorId = operatorId;
    this->operatorName = operatorName;
}

int Operator::getId() {
    return operatorId;
}

void Operator::assignTrip(Trip* t) {
    tripsHandled.push_back(t);
}

void Operator::showInfo() {
    cout << "Operator: " << operatorName << endl;

    for (int i = 0; i < tripsHandled.size(); i++) {
        tripsHandled[i]->display();
        cout << "----------------" << endl;
    }
}