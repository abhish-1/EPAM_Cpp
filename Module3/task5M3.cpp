//Defines a base class Employee with a virtual double calculatePay() 
// const function Derives a SalariedEmployee class with a fixed salary,
// and an HourlyEmployee class with hours and hourly rate Implements
// calculatePay() in both derived classes with their specific formulas 
// In main, creates base class pointers to different derived objects and 
// calls calculatePay() via the pointer.

#include<iostream>
class Employee {
public:
	virtual double calculatePay() const = 0;
};
class SalariedEmployee : public Employee {
	double salary;
public:
	SalariedEmployee(double salary) : salary(salary) {};
	double calculatePay() const {
		return salary;
	}
};
class HourlyEmployee : public Employee {
	double hours;
	double hourlyRate;
public:
	HourlyEmployee(double hours, double hourlyRate) : hours(hours), hourlyRate(hourlyRate) {};

	double calculatePay() const {
		return hours * hourlyRate;
	}
};


using namespace std;
int main() {
	vector<Employee*> arr;
	arr.push_back(new HourlyEmployee(5, 1400));
	arr.push_back(new SalariedEmployee(65000));

	for (int i = 0; i < 2; i++) {
		cout << arr[i]->calculatePay() << endl;


	}
	for (int i = 0; i < 2; i++) {
		delete(arr[i]);
		arr[i]->nullptr;

	}
	return 0;
}
