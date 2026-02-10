#include <iostream>
using namespace std;
class Device {
public:
    int id;

    void showId() {
        cout << "Device ID: " << id << endl;
    }
};
class Phone : public Device {
};

class Camera : public Device {
};

class Smartphone : public Phone, public Camera {
};

int main() {
    Smartphone s;
    s.Phone::id = 1;
    s.Camera::id = 2;
    s.Phone::showId();
    s.Camera::showId();
    return 0;
}
