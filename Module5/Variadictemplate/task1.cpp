// Task:
// Write a C++ program that:
// Defines a variadic template function printAll which prints all its arguments, separated by spaces or newlines.
// Implements a base case: an empty function (does nothing).
// Implements a recursive case: prints the first argument, then calls itself with the remaining arguments.
// Tests the function with printAll(1, 2.5, "Hello");.

#include<iostream>
using namespace std;
void printAll(){

}
template<typename T, typename... Rest>
void printAll(T first, Rest... rest){
    cout<<first<<endl;
    printAll(rest...);
}

int main(){
    printAll(7,77,8.34,"apple");
    return 0;
}