//Defines an abstract class Payment with a pure virtual function 
// processPayment(double amount) Implements concrete classes:'
// CreditCardPayment and PayPalPayment, each overriding
// processPayment(double) Creates a driver program that uses base
// class pointers to process payments through different derived 
// types (polymorphically) Demonstrates how implementation details 
// are hidden, and only the public interface is exposed

#include<iostream>
#include <vector>
using namespace std;
class Payment {
public:
	virtual void processPayment(double amount) = 0;
};
class CreditCardPayment : public Payment {
	void processPayment(double amount) override {
		cout << "payment gets processed via creadit card\n";
	}

};
class PayPalPayment : public Payment {
	void processPayment(double amount) override {
		cout << "payment gets processed via paypal\n";
	}

};
int main() {
	vector<Payment*> arr;
	arr.push_back(new CreditCardPayment);
	arr.push_back(new PayPalPayment);
	for (int i = 0; i < 2; i++) {
		arr[i]->processPayment(2909);
	}
	for (int i = 0; i < 2; i++) {
		delete(arr[i]);
	}

}