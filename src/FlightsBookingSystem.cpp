#include "FlightsBookingSystem.h"
#include "BankTransactions.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void FlightsBookingSystem::run()
{
    while (true) {
        FlightBooking booking;
        //BankTransactions bankTransaction;

        // Customer details
        cout << "Enter customer name:\n";
        cin >> name;
        booking.setCustomerName(name);


    }
}

