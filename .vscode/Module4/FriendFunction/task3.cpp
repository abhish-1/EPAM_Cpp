//Defines classes Rectangle (with private length and width) and Circle (with private radius) Declares
// a friend function compareArea(Rectangle, Circle) in both classes Implements compareArea(Rectangle, Circle)
// to calculate and compare the area of each shape, printing which has the larger area (or if they are equal)`
#include <iostream>
using namespace std;

class Circle;  
class Rectangle {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    friend void compareArea(Rectangle r, Circle c);
};

class Circle {
    double radius;
public:
    Circle(double r) : radius(r) {}
    friend void compareArea(Rectangle r, Circle c);
};

void compareArea(Rectangle r, Circle c) {
    double rectArea = r.length * r.width;
    double circleArea = 3.14159 * c.radius * c.radius;

    cout << "Rectangle area: " << rectArea << ", Circle area: " << circleArea << endl;

    if (rectArea > circleArea)
        cout << "Rectangle has larger area." << endl;
    else if (rectArea < circleArea)
        cout << "Circle has larger area." << endl;
    else
        cout << "Both have equal area." << endl;
}

int main() {
    Rectangle rect(5, 6);
    Circle cir(3);

    compareArea(rect, cir);

    return 0;
}
