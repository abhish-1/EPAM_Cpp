//Defines a base class Device (e.g., with an id or name member) 
// Derives Phone and Camera from Device using virtual inheritance
// Derives Smartphone from both Phone and Camera Demonstrates that
// Smartphone contains only one copy of Device’s members Shows 
// clear initialization and usage of Device’s data within Smartphone

#include<iostream>
using namespace std;
class Device {
	int id;
	public:
		Device(int id) {
			this->id = id;
			cout << "the adddress of the id is device" << &id;
		}
};
class Camera : virtual public Device {
public:
	Camera(int id) : Device(id) {};
	cout << "the adddress of the id is camera" << &id;
    }
};
class Phone : virtual public Device {
public:
	Phone(int id) : Device(id) {
		cout << "the adddress of the id is phone" << &id;
	}
};

class SmartPhone : public Camera, public Phone {
public:
	void getId() {
		cout << "The id is " << id;
		cout << "the adddress of the id is smartphon " << &id;
	}

};
int main() {
	Camera c1 = new Camera(5);
	Phone p1 = new Phone(50);
	Smartphone s1;
	s1.getId();


}