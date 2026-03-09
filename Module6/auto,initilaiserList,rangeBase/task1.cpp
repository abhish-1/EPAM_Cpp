// Declares variables using auto for int, double, and std::string.
// Assigns values to these variables.
// Prints their values and uses typeid(variable).name() to show the deduced type.
// Compares with explicit type declarations for the same values.

#include<iostream>
using namespace std;
int main(){
    int a =10;
    double d = 10.45;
    string str = "apple";
    auto a = {10,13,14};

    cout<<typeid(a).name()<<endl;
    cout<<typeid(d).name()<<endl;
    cout<<typeid(str).name()<<endl;
    cout<<typeid(a).name()<<endl;

}