//Defines a base class Vehicle with members : make(std::string),
// model(std::string) Derives a Car class from Vehicle, adding
// doors(int) Further derives an ElectricCar class from Car,
// adding batteryCapacity(double) Prints a message from each
// constructor to show the order of constructor calls Creates
// an ElectricCar object, passing values for all members, and
// observes output

#include<iostream>
using namespace std;
class Vehicle {
public:
	string make;
	string model;

	Vehicle(string make = "", string model = "") : make(make), model(model) {
		cout << "hey gentle here we have Vehicle type constructor gettin executed" << endl;

	}
};
class Car :public Vehicle {
public:
	int door;
	Car(string make, string model, int door = 0) : Vehicle(make, model), door(door) {
		cout << "hey gentle here we have Car type constructor gettin executed" << endl;
	}
};
class ElectricCar :public Car {
public:
	double batteryCapacity;
	ElectricCar(string make, string model, int doors, double batteryCapacity = 0.0) : Car(make, model, door), batteryCapacity(batteryCapacity) {
		cout << "hey gentle here we have ElectricCar type constructor gettin executed" << endl;
	}
};

int main() {
	Vehicle firstCar;
	cout << "-------------------------------------------------------------" << endl;
	ElectricCar eCar("honda", "civic", 4, 5000.00);
	cout << "-------------------------------------------------------------" << endl;

	Vehicle gaddi("honda", "civic");
	cout << gaddi.model << endl;
	cout << gaddi.make << endl;
	cout << "-------------------------------------------------------------" << endl;

}


