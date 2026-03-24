// Defines a base class Shape with a virtual destructor.
// Defines two derived classes: Circle and Rectangle, each with a method (draw() or circleSpecific()).
// Creates a Shape* that points to a Circle object.
// Attempts to downcast Shape* to Circle* using both static_cast and dynamic_cast.
// With static_cast, calls a derived-specific method (shows that it's unsafe if you cast to the wrong type!)
// With dynamic_cast, checks the result for nullptr before calling a derived method.
// Briefly discusses and prints the difference in safety.

#include<iostream>
#include <typeinfo>
using namespace std;
class Shape{
    public:
    Shape(){
        cout<<"cpnstructor called";
    }
    virtual ~Shape(){
        cout<<"destructor called";
    }
};
class Circle:public Shape{
    public:
    Circle(){
        cout<<"circle created"<<endl;
    }
    void draw(){
        cout<<"draw from circle"<<endl;
    }
    void circleSpecific(){
        cout<<"circlespecific"<<endl;
    }

};
class Rectangle:public Shape{
    public:
    void draw(){
        cout<<"draw from Rectangle"<<endl;
    }

};

int main(){
    Shape* s = new Circle();
    Circle* c1 = static_cast<Circle*> (s);
    Circle* c2 = dynamic_cast<Circle*> (s);
    c1->circleSpecific();
    cout<<c2<<endl;
    
    
    Rectangle* r = dynamic_cast<Rectangle*>(s); // Fails
    if (r) {
        r->draw();
    } else {
        std::cout << "dynamic_cast to Rectangle* failed (nullptr)\n";
    }

}