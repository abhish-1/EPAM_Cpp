// Defines a variadic function printAll(int a, Args... args) which prints all arguments.
// Calls it with more than one argument (e.g., printAll(1,2,3);) — this works.
// Calls it with just one argument (e.g., printAll(42);) — this also works.
// Calls it with zero arguments (e.g., printAll();) — this generates a compile-time error (no matching function).
// Fixes the implementation by adding a zero-argument base case void printAll();, so the recursive expansion now
// stops safely on zero arguments.

#include<iostream>
using namespace std;

void printAll(){}
template<typename T, typename ... Args>
void printAll(T a, Args... args){
    cout<<a<<endl;
    printAll(args...);
}

int main(){
    printAll(1,2,3);
    printAll(42);
    printAll();
}