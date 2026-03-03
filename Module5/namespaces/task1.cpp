// Write a C++ program that:
// Defines a namespace Geometry containing:
// A struct Point { int x, y; }
// A function printPoint(const Point&) that prints the point’s coordinates
// Demonstrates usage by:
// Creating a Geometry::Point variable
// Calling Geometry::printPoint to print it

#include<iostream>
using namespace std;
namespace Geometry{
    struct Point{
        int x,y;
    };
    void printPoint(const Point& p) {  
        cout << p.x << " " << p.y << endl; 
    }
}
int main(){
    Geometry::Point p;
    p.x=1;
    p.y=3;
    Geometry::printPoint(p);

}