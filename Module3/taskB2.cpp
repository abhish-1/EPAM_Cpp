#include <iostream>
using namespace std;

class Device {
public:
    int id;

    void showId() {
        cout << "Device ID: " << id << endl;
    }
};

class Phone : virtual public Device {
};

class Camera : virtual public Device {
};

class Smartphone : public Phone, public Camera {
};

int main() {
    Smartphone s;

    s.id = 2;
    s.showId();

    Device* d1 = static_cast<Phone*>(&s);
    Device* d2 = static_cast<Camera*>(&s);
    cout << "Device via Phone:  " << d1 << endl;
    cout << "Device via Camera: " << d2 << endl;
    return 0;
}
