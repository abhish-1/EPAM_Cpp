// Write a C++ program that: Defines a macro SQUARE(x) to compute x*x Creates a Math class 
//with an inline member function square() to compute square of a value Tests both approaches 
//with integers and expressions, such as SQUARE(1+2) Observes and demonstrates different 
//results, focusing on macro’s double evaluation and inline function’s type safety and reliability

#include<iostream>
#define SQUARE(x) x*x
using namespace std;
class Math{
    public:
    inline int square(int x) { 
        return (x)*(x);
    }
};

int main(){
    cout<<SQUARE(3)<<endl; //9
    cout<<SQUARE(1+2)<<endl; //5
    Math math;
    cout<<math.square(3)<<endl; //9
    cout<<math.square(1+2)<<endl; //9
    return 0;
}