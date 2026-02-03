//Defines a Car class with private data members representing engine details
// (e.g., bool engineOn, int speed, int rpm) Implements public functions: 
// start(), accelerate(), brake(), each manipulating the private engine 
// state internally. Prevents any direct access or modification of engine 
//details from outside the class Demonstrates use of this public API to 
// control the car in a simple and safe manner

#include<iostream>
#include<vector>
using namespace std;
class Car {
	bool engineOn = false;
	int speed = 0;
	int rpm = 0;

public:
	void start() {
		engineOn = true;
		cout << "engine starts" << endl;

	}
	void accelerate() {
		if (engineOn) {
			speed += 10;
			cout << "The speed is " << speed << endl;
		}
		else {
			cout << "Please start the engine" << endl;
		}

	}
	void brake() {
		if (engineOn) {
			speed -= 10;
			rpm -= 50;
			if (speed < 0) { speed = 0 };
			if (rpm < 0) { rpm = 0 };
			cout << "The speed is " << speed << endl;
		}
		else {
			cout << "Please start the engine" << endl;
		}
	}

};
int main() {
	c1.accelerate();
	c1.brake();
}