// Defines a function template:
// template<typename T> void showType(T t);
// For each call, prints the value and deduced type of t (using typeid(T).name() and/or decltype)
// Calls showType(10) and showType(3.14)

#include<iostream>
using namespace std;
template<typename T> 
void showType(T t){
    cout<<t<<" type"<<typeid(T).name()<<endl;
}
int main(){
    showType(10);
    showType(3.14);
}