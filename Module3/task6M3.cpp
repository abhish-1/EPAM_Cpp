//Defines a base class Printer with a virtual void print(const std::string& msg = "Base Printer") 
// Derives a ColorPrinter class that overrides print() and changes the default argument to 
// "Color Printer" Demonstrates calling print() both directly on a ColorPrinter object 
// (ColorPrinter cp; cp.print();) and through a base class pointer (Printer* p = &cp; p->print();) 
// without passing any arguments Observes and explains that the default argument is determined by
// pointer/reference type at compile time, but the function body executed is decided at run time

#include<iostream>
using namespace std;
class Printer {
public:
	virtual void print(const string& msg = "Base Printer") {
		cout << "Painter class" << endl;
		cout << msg;
	}
};

class ColorPrinter : public Printer {
public:
	void print(const string& msg = "color Printer") override {
		cout << msg << endl;
		cout << "Surprise" << endl;
	}
};
int main() {
	ColorPrinter cp;
	cp.print(); //color Printer Surprise

	Printer* p = &cp; //Base Printer Surprise
	//At compile time it holds up the parameter in Printer and while it actually runs that reaches to ColorPrinter
	//and executes that definition although holds the parameter from the Printer class's print.
	p->print();
}