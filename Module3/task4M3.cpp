//Defines an abstract base class Shape with a pure virtual function area() 
// Derives classes Circle, Rectangle, and Triangle, each implementing area() 
// with their own formulas Stores pointers to Shape objects in a std::vector
// Iterates through the vector, calling area() to compute the area of each 
// shape at run time

#include<iostream>
using namespace std;
class Shape {
public:
	virtual double area() = 0;
};
class Circle : public Shape {
public:
	int radius;
	Circle(int radius) : radius(radius) {};
	double area() {
		return 3.14 * radius * radius;
	}
};
class Rectangle : public Shape {
public:
	int length;
	int breadth;
	Rectangle(int length, int breadth) : length(length), breadth(breadth) {};
	double area() {
		return (length * breadth);
	}

};
class Triangle : public Shape {
private:
	int base;
	int height;
public:
	Triangle(int b, int h) : base(b), height(h) {};
	double area() {
		return 0.5f * base * height;
	}
};


int main() {
	vector<Shape*> arr;
	arr.push_back(new Rectangle(3, 4));
	arr.push_back(new Triangle(3, 4));
	arr.push_back(new Circle(3));
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i]->area() << endl;
		delete(arr[i]);
		arr[i] = nullptr;
	}
	return 0;
}