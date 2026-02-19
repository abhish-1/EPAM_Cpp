//Defines a class Box with private members: length, width, height Declares a friend function volume(Box) to compute and return the 
//box's volume In main(), creates a Box object and calls volume(Box) to calculate and print its volume

#include <iostream>
using namespace std;
class Box {
    int length, width, height;
public:
    Box(int l, int w, int h) : length(l), width(w), height(h) {}
    friend int volume(Box b);
};

int volume(Box b) {
    return b.length * b.width * b.height;
}

int main() {
    Box b(2, 3, 4);
    cout << "Volume: " << volume(b) << endl;
    return 0;
}
