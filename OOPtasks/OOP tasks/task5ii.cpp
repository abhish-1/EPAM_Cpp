//Write a C++ program that: Extends the DynamicArray class to print a message when its destructor is called. Create
//an array of DynamicArray objects inside a function (e.g., DynamicArray arr[3]) Observes and logs the order of destructor
//calls as the function scope ends Analyzes object lifetime and scope

#include<iostream>
using namespace std;
class DynamicArray{
public:
    ~DynamicArray() {
        cout<<"The array gets deleted with memory space ->"<<this<<endl;
    }
};

int main() {
    cout<<"Begin"<<endl;
    DynamicArray *arr = new DynamicArray[3];
    delete []arr;

    cout<<"Deletion completed."<<endl;
    return 0;

}