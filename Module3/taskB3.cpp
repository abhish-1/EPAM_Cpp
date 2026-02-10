#include <iostream>
using namespace std;

class Device {
public:
    Device() {
        cout << "Device constructor\n";
    }
};

class Phone : virtual public Device {
public:
    Phone() {
        cout << "Phone constructor\n";
    }
};

class Camera : virtual public Device {
public:
    Camera() {
        cout << "Camera constructor\n";
    }
};

class Smartphone : public Phone, public Camera {
public:
    Smartphone() {
        cout << "Smartphone constructor\n";
    }
};

int main() {
    Smartphone s;
    return 0;
}
