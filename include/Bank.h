#ifndef BANK_H
#define BANK_H
#include <string>

using namespace std;
class Bank
{
    public:
        // Functions to validate the debit card, send the verification code,
        //check the account balance and get the account balance
        bool validateDebitCard();
        string sendVerificationCode();
        bool checkBalance(double cost);
        double getAccountBalance();
    private:
        string cardNumber;
        double accountBalance;
};

#endif // BANK_H
