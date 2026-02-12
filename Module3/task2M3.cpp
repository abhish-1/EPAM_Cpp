//Defines a class Complex with data members: real (double) and imag
// (double) Overloads operator+ to add two Complex objects, returning
// their sum as a new Complex Overloads operator<< to print a Complex
// object in the form "a + bi" Creates and adds two Complex numbers
// in main, then displays the result using the overloaded operators

#include<iostream>
using namespace std;
class Complex {
	int real;
	int imag;
public:
	
	Complex(int a, int b) {
		this->real = a;
		this->imag = b;
	}
	friend Complex operator+ (const Complex& c,const Complex& c1) {
		return Complex(c1.real + c.real, c1.imag + c.imag);
		
	}
	friend ostream& operator<<(ostream& COUT, Complex& c){
		COUT<<c.real<<" + "<<c.imag<<"i"<<endl;
		return COUT;
	};
};

int main() {
	Complex c(5, 6);
	Complex c1(3, 4);
	Complex d = c + c1;
	cout<<d;
}