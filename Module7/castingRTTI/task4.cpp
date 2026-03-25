// Defines an int variable.
// Casts its address to char* using reinterpret_cast and prints each byte of the integer (shows endianness).
// Attempts an unsafe pointer cast between unrelated types (e.g., int* to double*), writes through it, and discusses the danger.
// Includes comments/discussion about why reinterpret_cast should be avoided except in rare, low-level cases.
#include<iostream>
using namespace std;
int main(){
    int a = 65436363;
    int* p = &a;
    char* add = reinterpret_cast<char*>(p);
    cout<<p<<endl;
    cout<<*(add)<<endl;
    cout<<*(++add)<<endl;
    cout<<*(++add)<<endl;
    cout<<*(++add)<<endl;
    double* ptr = reinterpret_cast<double*>(p);
    cout<<*ptr<<endl;
}