#include "BoardingPass.h"
#include <iostream>
#include <iomanip>

using namespace std;
void BoardingPass::printBoardingPass(const string& customerName, const string& flightClass, double cost,
                            const string& departureAirport, const string& departureDate,
                            const string& departureTime, const string& arrivalAirport,
                            const string& arrivalDate, const string& arrivalTime)
{
    // Output the boarding pass details with proper formatting
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Name: " << setw(26) << left << customerName  << "Class: " << flightClass << "\t\t\tCost: " << cost << " EUR\n\n";
    cout << "Departing\t\t\tDate\t\t\t\tTime\n";
    cout << departureAirport << "\t\t\t\t" << departureDate << "\t\t\t" << departureTime << "\n\n";
    cout << "Arriving\t\t\tDate\t\t\t\tTime\n";
    cout << arrivalAirport << "\t\t\t\t" << arrivalDate << "\t\t\t" << arrivalTime << "\n";
    cout << "--------------------------------------------------------------------------------\n";
}

