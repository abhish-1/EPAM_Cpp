#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;        
    virtual double perimeter() const = 0;   
    virtual ~Shape() = default; 
    //for inheritance + polymorphism,When you use new DerivedClass and store in BaseClass*
};

class Circle : public Shape {
    int radius;
public:
    Circle(int radius) : radius(radius) {}  

    double area() const override {          
        return 3.14 * radius * radius;   
    }

    double perimeter() const override {
        return 2 * 3.14* radius;       
    }
};

class Rectangle : public Shape {
    int length;
    int breadth;
public:
    Rectangle(int length, int breadth) : length(length), breadth(breadth) {}

    double area() const override {
        return length * breadth;            
    }

    double perimeter() const override {
        return 2 * (length + breadth);
    }
};

class Triangle : public Shape {
    int base;
    int height;
public:
    Triangle(int base, int height) : base(base), height(height) {}

    double area() const override {
        return 0.5 * base * height;
    }

    double perimeter() const override {
        double hypotenuse = sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle(8));
    shapes.push_back(new Rectangle(8, 10));
    shapes.push_back(new Triangle(8, 4));

    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "Shape " << i + 1 << endl;
        cout << "  Area: " << shapes[i]->area() << endl;
        cout << "  Perimeter: " << shapes[i]->perimeter() << endl;
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}