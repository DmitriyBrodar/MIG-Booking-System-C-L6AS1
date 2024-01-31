#include "Booking.h"
#include "Bank.h"
#include "BoardingPass.h"
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;
void Booking::processBooking()
{
    char choice;

    // Get the current time and date
    time_t now = time(0);
    char* timeAndDate = ctime(&now);

    // Prompt the user to enter customer and flight details
    customer.enterCustomerDetails();
    flight.enterFlightDetails();

    // Prompt the user to finalize the booking
    cout << "\nDo you want to finalize the booking (Yes: 1 or No: 2): ";
    cin >> choice;

    // Validate user input
    while (choice != '1' && choice != '2') {
            cout << "You entered a wrong number. Please choose 1 for finalize booking or 2 for Finish booking:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
    }

    if (choice == '1') {

        double balance;

        // Validate the debit card and process the transaction
        if (bank.validateDebitCard()) {
            // Generate and send verification code
            string verificationCode = bank.sendVerificationCode();

            // Verify verification code
            int attempts = 0;
            string userVerificationCode;
            bool codeOk = false;

            do {
                cout << "\nEnter the verification code received: ";
                cin >> userVerificationCode;
                attempts++;

                if (userVerificationCode == verificationCode) {

                    // If verif code was successful check the cost
                    cout << "\nVerification code is valid.\n";

                    double cost = flight.getCost();

                    if (bank.checkBalance(cost)) {

                        cout << "\nYou have enough money on your balance for transaction: " << bank.getAccountBalance() << " EUR\n\n";

                        // Generate a booking code
                        string departureDate = flight.getDepartureDate();
                        string departureTime = flight.getDepartureTime();

                        departureDate.erase(remove(departureDate.begin(), departureDate.end(), '/'), departureDate.end());
                        departureTime.erase(remove(departureTime.begin(), departureTime.end(), ':'), departureTime.end());

                        string bookingCode = "MIG" + departureDate + departureTime + flight.getDepartureAirport() + flight.getArrivalAirport();

                        // Print the boarding pass
                        BoardingPass boardingPass;
                        boardingPass.printBoardingPass(customer.getName(), customer.getFlightClass(), cost,
                                                   flight.getDepartureAirport(), flight.getDepartureDate(), flight.getDepartureTime(),
                                                   flight.getArrivalAirport(), flight.getArrivalDate(), flight.getArrivalTime());

                        // Display booking success message
                        cout << "\nBooking successful. Your booking code is: " << bookingCode << ".\n";
                        codeOk = true;
                    } else {
                        // Display insufficient funds message
                        cout << "\nDate and time: " << string(timeAndDate);
                        cout << "AIB bank. Insufficient funds. Booking failed. \n";
                        cout << "Your card balance is: " << bank.getAccountBalance() << " EUR\n";
                        codeOk = true;
                        }

                } else {
                    // Display incorrect verification code message
                    cout << "Verification code is incorrect. You have " << 3 - attempts << " attempts left to enter the valid code\n";
                }
            } while (attempts < 3 && !codeOk);
                // Display maximum attempts reached message
                if (attempts == 3) {
                    // Maximum attempts is reached
                    cout << "\nMaximum attempts is reached. Booking failed.\n";
                }
        } else {
            // Display debit card verification failure message
            cout << "Debit card verification failed. Booking failed.\n";
        }
    } else {
        // Display booking cancellation message
        cout << "Booking cancelled.\n";
    }
}


