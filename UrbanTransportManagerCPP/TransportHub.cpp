#include "TransportHub.h"

void TransportHub::addOperator() {
    int id;
    string name;

    cout << "Enter Operator ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Operator Name: ";
    getline(cin, name);

    allOperators.push_back(Operator(id, name));
    cout << "Operator added successfully." << endl;
}

void TransportHub::addCustomer() {
    string name;

    cin.ignore();
    cout << "Enter Customer Name: ";
    getline(cin, name);

    allCustomers.push_back(Customer(name));
    cout << "Customer added successfully." << endl;
}

void TransportHub::createTrip() {
    int type;
    int code;
    string startPoint;
    string endPoint;
    float distance;

    cout << "Select Trip Type" << endl;
    cout << "1. Mini Trip" << endl;
    cout << "2. Elite Trip" << endl;
    cout << "Enter choice: ";
    cin >> type;

    cout << "Enter Trip Code: ";
    cin >> code;
    cin.ignore();

    cout << "Enter Start Point: ";
    getline(cin, startPoint);

    cout << "Enter End Point: ";
    getline(cin, endPoint);

    cout << "Enter Distance: ";
    cin >> distance;

    if (type == 1) {
        allTrips.push_back(new MiniTrip(code, startPoint, endPoint, distance));
        cout << "Mini trip created successfully." << endl;
    }
    else if (type == 2) {
        float comfortFee;
        cout << "Enter Comfort Fee: ";
        cin >> comfortFee;
        allTrips.push_back(new EliteTrip(code, startPoint, endPoint, distance, comfortFee));
        cout << "Elite trip created successfully." << endl;
    }
    else {
        cout << "Invalid trip type." << endl;
    }
}

void TransportHub::assignTripToOperator() {
    if (allOperators.empty()) {
        cout << "No operators available." << endl;
        return;
    }

    if (allTrips.empty()) {
        cout << "No trips available." << endl;
        return;
    }

    int operatorId;
    int tripCode;
    bool operatorFound = false;
    bool tripFound = false;

    cout << "Enter Operator ID: ";
    cin >> operatorId;

    cout << "Enter Trip Code: ";
    cin >> tripCode;

    for (int i = 0; i < allOperators.size(); i++) {
        if (allOperators[i].getId() == operatorId) {
            operatorFound = true;

            for (int j = 0; j < allTrips.size(); j++) {
                if (allTrips[j]->getTripCode() == tripCode) {
                    allOperators[i].assignTrip(allTrips[j]);
                    tripFound = true;
                    cout << "Trip assigned to operator successfully." << endl;
                    break;
                }
            }
            break;
        }
    }

    if (!operatorFound) {
        cout << "Operator not found." << endl;
    }
    else if (!tripFound) {
        cout << "Trip not found." << endl;
    }
}

void TransportHub::assignTripToCustomer() {
    if (allCustomers.empty()) {
        cout << "No customers available." << endl;
        return;
    }

    if (allTrips.empty()) {
        cout << "No trips available." << endl;
        return;
    }

    int customerIndex;
    int tripCode;
    bool tripFound = false;

    cout << "Available Customers:" << endl;
    for (int i = 0; i < allCustomers.size(); i++) {
        cout << i + 1 << ". Customer " << i + 1 << endl;
    }

    cout << "Select Customer Number: ";
    cin >> customerIndex;

    if (customerIndex < 1 || customerIndex > allCustomers.size()) {
        cout << "Invalid customer selection." << endl;
        return;
    }

    cout << "Enter Trip Code: ";
    cin >> tripCode;

    for (int j = 0; j < allTrips.size(); j++) {
        if (allTrips[j]->getTripCode() == tripCode) {
            allCustomers[customerIndex - 1].bookTrip(allTrips[j]);
            tripFound = true;
            cout << "Trip assigned to customer successfully." << endl;
            break;
        }
    }

    if (!tripFound) {
        cout << "Trip not found." << endl;
    }
}

void TransportHub::showAllTrips() {
    if (allTrips.empty()) {
        cout << "No trips available." << endl;
        return;
    }

    cout << endl;
    cout << "All Trips" << endl;

    for (int i = 0; i < allTrips.size(); i++) {
        allTrips[i]->display();
        cout << "------------------------" << endl;
    }
}

void TransportHub::showAllOperators() {
    if (allOperators.empty()) {
        cout << "No operators available." << endl;
        return;
    }

    cout << endl;
    cout << "All Operators" << endl;

    for (int i = 0; i < allOperators.size(); i++) {
        allOperators[i].showInfo();
        cout << "------------------------" << endl;
    }
}

void TransportHub::showAllCustomers() {
    if (allCustomers.empty()) {
        cout << "No customers available." << endl;
        return;
    }

    cout << endl;
    cout << "All Customers" << endl;

    for (int i = 0; i < allCustomers.size(); i++) {
        cout << "Customer " << i + 1 << endl;
        allCustomers[i].showBookings();
        cout << "------------------------" << endl;
    }
}

void TransportHub::showCustomerTrips() {
    if (allCustomers.empty()) {
        cout << "No customers available." << endl;
        return;
    }

    int customerIndex;

    cout << "Select Customer Number: ";
    cin >> customerIndex;

    if (customerIndex < 1 || customerIndex > allCustomers.size()) {
        cout << "Invalid customer number." << endl;
        return;
    }

    allCustomers[customerIndex - 1].showBookings();
}

void TransportHub::showOperatorTrips() {
    if (allOperators.empty()) {
        cout << "No operators available." << endl;
        return;
    }

    int operatorId;
    bool found = false;

    cout << "Enter Operator ID: ";
    cin >> operatorId;

    for (int i = 0; i < allOperators.size(); i++) {
        if (allOperators[i].getId() == operatorId) {
            allOperators[i].showInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Operator not found." << endl;
    }
}

void TransportHub::menu() {
    int choice;

    do {
        cout << endl;
        cout << "===== Urban Transport Manager =====" << endl;
        cout << "1. Add Operator" << endl;
        cout << "2. Add Customer" << endl;
        cout << "3. Create Trip" << endl;
        cout << "4. Assign Trip To Operator" << endl;
        cout << "5. Assign Trip To Customer" << endl;
        cout << "6. Show All Trips" << endl;
        cout << "7. Show All Operators" << endl;
        cout << "8. Show All Customers" << endl;
        cout << "9. Show Customer Trips" << endl;
        cout << "10. Show Operator Trips" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addOperator();
            break;
        case 2:
            addCustomer();
            break;
        case 3:
            createTrip();
            break;
        case 4:
            assignTripToOperator();
            break;
        case 5:
            assignTripToCustomer();
            break;
        case 6:
            showAllTrips();
            break;
        case 7:
            showAllOperators();
            break;
        case 8:
            showAllCustomers();
            break;
        case 9:
            showCustomerTrips();
            break;
        case 10:
            showOperatorTrips();
            break;
        case 0:
            cout << "Closing system." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);
}