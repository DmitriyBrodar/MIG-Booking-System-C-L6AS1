#ifndef BOARDINGPASS_H
#define BOARDINGPASS_H
#include <string>

using namespace std;
class BoardingPass
{
    public:
        // Function to print the boarding pass
        void printBoardingPass (const string& customerName, const string& flightClass, double cost,
                            const string& departureAirport, const string& departureDate,
                            const string& departureTime, const string& arrivalAirport,
                            const string& arrivalDate, const string& arrivalTime);
};

#endif // BOARDINGPASS_H
