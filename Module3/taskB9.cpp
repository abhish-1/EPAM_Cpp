//Uses the Shape hierarchy(Shape with pure virtual area() and perimeter(),
// and derived classes Circle, Rectangle, Triangle) Creates a std::vector<Shape*> 
// and stores dynamically created shape objects in it Loops over the vector,
// invoking area() and perimeter() polymorphically for each shape Deletes each
// object after use, demonstrating destructors running in proper order

#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() override { return 3.14 * r * r; }
    double perimeter() override { return 2 * 3.14 * r; }
    ~Circle() { cout << "Circle destroyed\n"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}
    double area() override { return w * h; }
    double perimeter() override { return 2 * (w + h); }
    ~Rectangle() { cout << "Rectangle destroyed\n"; }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(2));
    shapes.push_back(new Rectangle(3, 4));

    for (Shape* s : shapes) {
        cout << s->area() << "," << s->perimeter() << endl;
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}
