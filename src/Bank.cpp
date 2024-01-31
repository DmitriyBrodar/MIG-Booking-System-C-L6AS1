#include "Bank.h"
#include <iostream>
#include <time.h>
#include<fstream>

using namespace std;
bool Bank::validateDebitCard()
{
    string savedCardNumber;
    bool cardFound = false;

    // Open the file in read mode
    ifstream debitCardFile("CreditCardDetails.txt");

    // Check if the file is opened successfully
    if (!debitCardFile) {
        cerr << "Error: Unable to open DebitCardDetails.txt\n";
        return false;  // Return false as an indication of failure
    }

    // Loop for infinite retries until the correct card number is entered
    while (true) {
        // Get debit card number from the user
        cout << "\nEnter debit card number (16 digits): ";
        cin >> cardNumber;

        // Check if the entered card number has exactly 16 characters
        if (cardNumber.length() != 16) {
            cout << "Invalid card number. Please enter 16 digits.\n";
            continue;  // Retry the loop
        }

        // Reset the file cursor to the beginning for each retry
        debitCardFile.clear();
        debitCardFile.seekg(0);

        // Loop through the file to find the card number
        while (debitCardFile >> savedCardNumber >> accountBalance) {
            if (cardNumber == savedCardNumber) {
                cardFound = true;
                break;
            }
        }

        if (cardFound) {
            // Exit the loop if the card is found
            break;
        } else {
            // Inform the user and retry the loop
            cout << "Invalid debit card number. Please try again.\n";
        }
    }

    // Close the file
    debitCardFile.close();

    return true;
}
string Bank::sendVerificationCode()
{
    time_t now = time(0);
    char* timeAndDate = ctime(&now);

    unsigned short verificationCode;

    srand (time(0));
    verificationCode = rand() % 9000 + 1000;
    cout << "\nDate and time: " << string(timeAndDate);
    cout << "----------------------------------------\n";
    cout << "AIB bank. The verification code is: " << verificationCode << "\n";
    return to_string(verificationCode);
}

bool Bank::checkBalance(double cost)
{
    // Check if there are sufficient funds in the account
    if (accountBalance >= cost) {
        return true;

        //accountBalance = accountBalance - cost;

    } else {

        return false;
    }
}

double Bank::getAccountBalance() {
    return accountBalance;
}

