#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
#include <string>

using namespace std;

class FlightBooking
{
    private:
        string customerName;
        string flightClass;
        string departureAirport;
        string departureDate;
        string departureTime;
        string arrivalAirport;
        string arrivalDate;
        string arrivalTime;
        double flightCost;
        string bookingCode;

    public:
        FlightBooking();

        void setCustomerName(string& name);
        void setFlightClass(string& flClass);
        void setDepartureAirport(string& depAirport);
        void setDepartureDate(string& depDate);
        void setDepartureTime(string& depTime);
        void setArrivalAirport(string& arrAirport);
        void setArrivalDate(string& arrDate);
        void setArrivalTime(string& arrTime);
        void setFlightCost(double& flCost);
        void setBookingCode(string& bookCode);

        string getBookingCode();

        bool verifyBooking();
        void printBoardingPass();

};

#endif // FLIGHTBOOKING_H
