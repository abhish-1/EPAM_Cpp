// Defines a function template:
// template<typename T> T add(T a, T b)
// which returns the sum of a and b
// Tests the template with int, double, and float types

#include<iostream>
using namespace std;
template<typenameT>
auto add(T a, T b){
    return (a+b);
}
int main(){
    cout<<add(3.2,4.6)<<endl;
    cout<<add(2,4)<<endl;
    cout<<add(6.4f,33.2)<<endl;
    return 0;
}