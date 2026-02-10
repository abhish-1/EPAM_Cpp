//Defines a Calculator class Implements overloaded add() methods:
// int add(int, int), double add(double, double), and std::string
// add(const std::string&, const std::string&) In main(), calls each 
// version of add() to observe compile-time selection based on argument types

#include<iostream>
#include<string>
using namespace std;
class Calculator {
	int add(int a, int b) {
		return a + b;
	}
	double add(double a, double b) {
		return a + b;
	}
	string add(const string& a, const string& b) {
		return a + b;
	}

};

int main() {
	Calculator c;
	cout<<c.add(6, 4)<<endl;
	cout<<c.add(4.6, 9.3)<<endl;
	cout<<c.add("abhishek", "Kumar")<<endl;
}
