//Defines a class Complex with data members: real (double) and imag
// (double) Overloads operator+ to add two Complex objects, returning
// their sum as a new Complex Overloads operator<< to print a Complex
// object in the form "a + bi" Creates and adds two Complex numbers
// in main, then displays the result using the overloaded operators

#include<iostream>
using namespace std;
class Complex {
public:
	double real;
	double imag;
	Complex(int a, int b) {
		this->real = a;
		this->imag = b;
	}
	Complex operator+ (const Complex& c) {
		return Complex(this->real + c.real, imag + c.imag);
	}
	void shoe() {
		cout << real << " + " << imag << "i" << endl;
			
	}

};
int main() {
	Complex c(5, 6);
	Complex d = c + d(4.2);
	d.shoe();
}