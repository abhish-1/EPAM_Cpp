// Uses the previous namespace Geometry with struct Point and void printPoint(const Point&)
// Adds a namespace alias: namespace G = Geometry;
// Demonstrates accessing Point and printPoint using alias: G::Point, G::printPoint

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
auto& G = Geometry::printPoint;
int main(){
    Geometry::Point p;
    p.x=1;
    p.y=3;
    G(p);
    Geometry::Point q;
    q.x=4;
    q.y=3;
    G(q);
}