/*
    Author: Dmytro Brodar
    Data: 29/01/2024

    "Morrison’s Island Getaways Booking Service"

    This booking program helps users reserve flights. Users enter their details
    and flight data. It prompts user to confirm their booking, verifies payment using a debit card,
    and generates ticket and a unique code for successful transactions.
    If there are issues with payment or verification, program cancels the booking.
*/
#include "Booking.h"
#include <iostream>
#include <limits>
#include <BoardingPass.h>
using namespace std;

int main()
{
    Booking booking;
    char choice;
    char bookingChoice;

    // Display the title for the booking service
    cout << "\t\tMorrison’s Island Getaways Booking Service\n\n";

    // Prompt the user to choose between booking a flight or exit from program
    cout << "Booking flight: 1\n";
    cout << "Close booking: 2\n";
    cin >> bookingChoice;

    // Validate user input
    while (bookingChoice != '1' && bookingChoice != '2') {
            cout << "You entered a wrong number. Please choose 1 for booking Flight or 2 for Cancel booking:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> bookingChoice;
    }

    // Process of the user's choice
    if (bookingChoice == '1') {
        do {
            booking.processBooking();

            // Ask the user if they want to make another booking
            cout << "\nDo you want to another flight booking? (Yes: 1 or No: 2): ";
            cin >> choice;

            // Validate user input
            while (choice != '1' && choice != '2') {
            cout << "You entered a wrong number. Please choose 1 for another booking or 2 for Finish booking:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
            }

        } while (choice == '1');

    // Finish program
    } else {
        cout << "Booking canceled.\n";

    }
    return 0;
}
