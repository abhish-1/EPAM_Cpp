// Declares int x = 10; and int* ptr = &x;
// Deduces a variable auto p = ptr; (pointer type) and a reference auto& r = x; (reference type)
// Modifies x using r; modifies x through *p
// Prints x, *p, and r to verify all refer to the same value

#include<iostream>
using namespace std;
int main(){
    int x =10;
    int* ptr = &x;
    auto p = ptr;
    auto& r = x;
    cout<<typename(r).name();
}