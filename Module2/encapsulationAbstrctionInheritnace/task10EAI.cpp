#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual void display() {
        cout << "I am a Shape" << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return 3.14 * radius * radius;
    }

    void display() override {
        cout << "Circle with radius " << radius << endl;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}

    double area() override {
        return side * side;
    }

    void display() override {
        cout << "Square with side " << side << endl;
    }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle " << length << "x" << width << endl;
    }
};

int main() {
    Shape* shapes[3];

    shapes[0] = new Circle(5);
    shapes[1] = new Square(4);
    shapes[2] = new Rectangle(3, 6);

    for (int i = 0; i < 3; i++) {
        shapes[i]->display();
        cout << "Area in this case . " << shapes[i]->area() << endl << endl;
        delete shapes[i];
    }

    return 0;
}