#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() {} 
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}

    double area() const override {
        return M_PI * r * r;
    }

    double perimeter() const override {
        return 2 * M_PI * r;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}

    double area() const override {
        return w * h;
    }

    double perimeter() const override {
        return 2 * (w + h);
    }
};
class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}

    double area() const override {
        double s = (a + b + c) / 2;  
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override {
        return a + b + c;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4, 5));
    for (Shape* s : shapes) {
        cout << "Area: " << s->area()
            << ", Perimeter: " << s->perimeter() << endl;
    }
    for (Shape* s : shapes) {
        delete s;
    }
    return 0;
}
