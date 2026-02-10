#include <iostream>
using namespace std;
class Payment {
public:
    virtual void process(double amount) = 0;
    virtual ~Payment() {}
};
class CreditCardPayment : public Payment {
public:
    void process(double amount) override {
        cout << "Processing credit card payment of rupesh" << amount << endl;
    }
};
class PayPalPayment : public Payment {
public:
    void process(double amount) override {
        cout << "Processing PayPal payment of rupees" << amount << endl;
    }
};

int main() {
    Payment* payment;
    CreditCardPayment cc;
    PayPalPayment pp;

    payment = dynamic_cast<Payment*>(&cc);
    payment->process(130.75);

    payment = dynamic_cast<Payment*>(&pp);
    payment->process(9.78);

    return 0;
}
