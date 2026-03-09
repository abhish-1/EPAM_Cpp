// Defines a class template with a default type:
// template<typename T = int> class Number { T value; public: Number(T v); void print(); };
// Instantiates Number<> (uses int as default type) and Number<double>
// Calls print() on both to show the values and types are as expected

#include<iostream>
using namespace std;
template<typename T = int> 
class Number { 
    T value;
    public: 
    Number(T v): value(v){}
    void print(){
        cout<<value<<endl;
    } 
};

int main(){
    Number n(32);
    n.print();
    Number<double> n1(23.4);
    n1.print();
}