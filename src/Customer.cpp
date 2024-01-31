#include "Customer.h"
#include <iostream>
#include <limits>

using namespace std;

void Customer::enterCustomerDetails()
{
    // Prompt the user to enter their name
    cout << "\nEnter customer name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    // Validate and prompt the user to enter the flight class
    while (true) {
        cout << "Enter flight class (1 for Economy or 2 for Business): ";
        cin >> flightClass;

        if (flightClass == "1" || flightClass == "2") {
            break;
        } else {
            cout << "Invalid input. Please enter 1 for Economy or 2 for Business class.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}

string Customer::getName() {
    return name;
}

string Customer::getFlightClass () {

    // Convert flight class from numeric to descriptive
    string fClass = flightClass;
    if (fClass == "1") {
        fClass = "Economy";
    } else {
        fClass = "Business";
    }

    return fClass;
}
