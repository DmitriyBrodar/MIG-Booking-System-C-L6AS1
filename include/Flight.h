#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>

using namespace std;
class Flight
{
    public:
        void enterFlightDetails();
        bool verifyDate(string& date);
        bool verifyTime(string& time);
        bool verifyAirportCode(string& code);
        bool verifyCost(double& cost);

        string getDepartureAirport();
        string getDepartureDate();
        string getDepartureTime();
        string getArrivalAirport();
        string getArrivalDate();
        string getArrivalTime();
        double getCost();

    private:
        string departureAirport;
        string departureDate;
        string departureTime;
        string arrivalAirport;
        string arrivalDate;
        string arrivalTime;
        double cost;
};

#endif // FLIGHT_H
