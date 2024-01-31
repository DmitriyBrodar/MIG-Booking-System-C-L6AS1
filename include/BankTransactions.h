#ifndef BANKTRANSACTIONS_H
#define BANKTRANSACTIONS_H
#include <string>

using namespace std;
class BankTransactions
{
    private:
        string debitCardNumber;
        double accountBalance;

    public:
        BankTransactions();

        void setDebitCardNumber(string& cardNumber);

        bool sendToBank();
        bool verifyDebitCard();
        bool checkBalance();
};

#endif // BANKTRANSACTIONS_H
