//Task:
//Write a C++ program that : Defines a struct Point with members x and y(default public access, struct Point) 
//Defines a class Rectangle with members length and width(default private access, class Rectangle) Provides 
//functions to set and print the Point's x/y values and Rectangle's length / width Observes and demonstrates 
//how default access specifiers affect direct member access and function design

#include<iostream>
#include<string>
struct Point {
	int x;
	int y;
	void setX(int X) {
		this->x = X;
	}
	void setY(int Y) {
		this->y = Y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}


};

//access through a struct is easy and has no restriction.

class Rectangle {
	int length;
	int breadth;

public:
	void setLength(int length) {
		this->length = length;
	}
	void setBreadth(int breadth) {
		this->breadth = breadth;
	}
	int getLength() {
		return length;
	}
	int getBreadth() {
		return breadth;
	}

};
// by default definitions are private in the class, unless specifically defined under public.

int main() {
	Point p;
	p.x = 10;      
	p.y = 20;      // works

	Rectangle r;
	// r.length = 5;   //  private member
	// r.breadth = 4;  // errorr.

	r.setLength(5);   
	r.setBreadth(4);

}


