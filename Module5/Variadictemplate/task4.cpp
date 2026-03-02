// Defines a function forwardAll(Args&&... args) that forwards all its arguments to another function process(args...)
// In forwardAll, uses std::forward<Args>(args)... to preserve argument categories
// Implements process(...) that prints the arguments (can use the variadic template approach)
// Tests by passing both lvalues and rvalues

#include<iostream>
#include <utility>
using namespace std;
void process(int &x){ cout << "Lvalue int: " << x << endl; }
void process(int&& x){ cout << "Rvalue int: " << x << endl; }
void process(double &x){ cout << "Lvalue double: " << x << endl; }
void process(double&& x){ cout << "Rvalue double: " << x << endl; }
void process(const char* x){ cout << "String: " << x << endl; }

template<typename T>
void process(T&& x) {
    cout << "Generic: " << x << endl;
}
template<typename... Args>
void forwardAll(Args&&... args){
    (process(forward<Args>(args)), ...);
}
int main(){
    int a =1;
    forwardAll(233, "apple",8.23);
    forwardAll(a);
    return 0;
}