#include "Flight.h"
#include <iostream>
#include <cctype>
#include <time.h>
#include <limits>
#include <cctype>

using namespace std;

void Flight::enterFlightDetails()
{
    // Prompt the user to enter flight details
    cout << "\nEnter departure airport (3-letters code): ";
    cin >> departureAirport;

    // Validate departure airport code
    while (!verifyAirportCode(departureAirport)) {
        cout << "Invalid airport code. Please enter a 3 letters code: ";
        cin >> departureAirport;
    }

    // Prompt the user to enter departure date
    cout << "Enter departure date in format (dd/mm/yyyy): ";
    cin >> departureDate;

    // Validate departure date
    while (!verifyDate(departureDate)) {
        cout << "\nInvalid departure date, enter please date in format(dd/mm/yyyy): ";
        cin >> departureDate;
    }

    // Prompt the user to enter departure time
    cout << "Enter departure time in format (hh:mm): ";
    cin >> departureTime;

    // Validate departure time
    while (!verifyTime(departureTime)) {
        cout << "\nInvalid departure time, enter please time in format(hh:mm): ";
        cin >> departureTime;
    }

    // Prompt the user to enter flight details
    cout << "\nEnter arrival airport (3-letters code): ";
    cin >> arrivalAirport;

    // Validate arrival airport code
    while (!verifyAirportCode(arrivalAirport)) {
        cout << "Invalid airport code. Please enter a 3 letters code: ";
        cin >> arrivalAirport;
    }

    // Prompt the user to enter arrival date
    cout << "Enter arrival date in format (dd/mm/yyyy): ";
    cin >> arrivalDate;

    // Validate arrival date
    while (!verifyDate(arrivalDate)) {
        cout << "\nInvalid departure date, enter please date in format(dd/mm/yyyy): ";
        cin >> arrivalDate;
    }

    // Prompt the user to enter arrival time
    cout << "Enter arrival time in format (hh:mm): ";
    cin >> arrivalTime;

    // Validate arrival time
    while (!verifyTime(arrivalTime)) {
        cout << "\nInvalid arrival time, enter please time in format(hh:mm): ";
        cin >> arrivalTime;
    }

    // Prompt the user to enter cost of the flight
    cout << "\nEnter the cost of the flight EUR: ";
    cin >> cost;

    // Validate cost
    while (!verifyCost(cost)) {
        cout << "Invalid input, enter please a positive decimal number: ";
        cin >> cost;
    }
}

bool Flight::verifyAirportCode(string& code) {
    // Check that code is 3 letters
    if (code.length() !=3)
        return false;

    // Check that it's a letter
    for (char c : code) {
        if(!isalpha(c))
            return false;
    }

    // Convert to upper
    for (char& c : departureAirport) {
        c = toupper(c);
    }
    return true;

}

bool Flight::verifyDate(string& date) {
    // check if the date format is correct
    if (date.size() !=10 || date[2] != '/' || date[5] != '/') {
        return false;
    }

    // extract day, month and year for checking
    int day = stoi(date.substr(0,2));
    int month = stoi(date.substr(3,2));
    int year = stoi(date.substr(6,4));

    // Check entered day, month and year.
    if (day < 1 || day > 31) {
        cout << "\nInvalid day entered. Please input a valid day between 1 and 31.";
    }

    if (month <1 || month > 12) {
        cout << "\nInvalid month entered. Please input a valid month between 1 and 12.";
    }

    if (year < 2023) {
        cout << "\nInvalid year entered. Please enter a valid year starting from 2023.";
    }

    // check dates range
    return (day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 2023);
}

bool Flight::verifyTime(string& time) {
    // check if the time format is correct
    if (time.size() !=5 || time[2] !=':') {
        return false;
    }

    // extract hours and minutes
    int hour = stoi(time.substr(0,2));
    int minute = stoi(time.substr(3,2));

    // Check the hour and minute here and output a suitable error message.
    if (hour < 0 || hour > 23) {
        cout << "\nInvalid hour entered. Please input a valid hour between 0 and 23.";
    }
    if (minute < 0 || minute > 59) {
        cout << "\nInvalid minutes entered. Please input a valid minutes between 0 and 59.";
    }

    // check time range
    return (hour >= 0 && hour <= 23) && (minute >= 0 && minute <= 59);
}

bool Flight::verifyCost(double& cost) {
    // Check if input is numeric and non-negative
    if (cin.fail() || cost < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

string Flight::getDepartureAirport() {
    // Convert to uppercase and return
    string res = departureAirport;

    for (char& c : res) {
        c = toupper(c);
    }

    return res;
}

string Flight::getDepartureDate() {
    return departureDate;
}

string Flight::getDepartureTime() {
    return departureTime;
}

string Flight::getArrivalAirport() {
    string res = arrivalAirport;

    for(char& c : res) {
        c = toupper(c);
    }

    return res;
}

string Flight::getArrivalDate() {
    return arrivalDate;
}

string Flight::getArrivalTime() {
    return arrivalTime;
}

double Flight::getCost () {
    return cost;
}
