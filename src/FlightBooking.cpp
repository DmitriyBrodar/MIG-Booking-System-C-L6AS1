#include "FlightBooking.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

FlightBooking::FlightBooking() : flightCost(0.0) {}

void FlightBooking::setCustomerName(string& name) {
    customerName = name;
}

void FlightBooking::setFlightClass(string& flClass) {
    flightClass = flClass;
}

void FlightBooking::setDepartureAirport(string& depAirport) {
    departureAirport = depAirport;
}

void FlightBooking::setDepartureDate(string& depDate) {
    departureDate = depDate;
}

void FlightBooking::setDepartureTime(string& depTime) {
    departureTime = depTime;
}

void FlightBooking::setArrivalAirport(string& arrAirport) {
    arrivalAirport = arrAirport;
}

void FlightBooking::setArrivalDate(string& arrDate) {
    arrivalDate = arrDate
}

void FlightBooking::setArrivalTime(string& arrTime) {
    arrivalTime = arrTime;
}

void FlightBooking::setFlightCost(double& flCost) {
    flightCost = flCost;
}

void FlightBooking::setBookingCode(string& bookCode) {
    bookingCode = bookCode;
}

string FlightBooking::getBookingCode() {
    return bookingCode;
}

bool FlightBooking::verifyBooking () {

}

void FlightBooking::printBoardingPass () {

}
