// Defines a class template:
// template<typename T> class Box { T value; public: Box(T v); void print(); };
// Implements the constructor and print method.
// Instantiates Box<int> and Box<std::string> objects, and prints their values.

#include<iostream>
using namespace std;
template<typename T>
class Box{
    T value;
    public:
    Box( T v){
        value=v;
    }
    void print(){
        cout<<value<<endl;
    }
}

int main(){
    int a =56;
    Box(a);
    Box(32);
    Box(43.5);
}