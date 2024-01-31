#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;
class Customer
{
    public:
        void enterCustomerDetails();
        string getName();
        string getFlightClass();

    private:
        string name;
        string flightClass;
};

#endif // CUSTOMER_H
