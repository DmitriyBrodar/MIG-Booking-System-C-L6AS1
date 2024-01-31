#ifndef BOOKING_H
#define BOOKING_H
#include "Customer.h"
#include "Flight.h"
#include "Bank.h"
#include <iostream>
#include <iomanip>

using namespace std;
class Booking
{
    public:
        // Function to process the flight booking
        void processBooking();

    private:
        Customer customer;
        Flight flight;
        Bank bank;

};

#endif // BOOKING_H
