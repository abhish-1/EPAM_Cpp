//Write a C++ program that: Extends the DynamicArray class to print a
//message when its destructor is called. Create an array of DynamicArray 
//objects inside a function (e.g., DynamicArray arr[3]) Observes and logs
//the order of destructor calls as function scope ends Analyzes lifetime, cope

#include<iostream>
using namespace std;
class DynamicArray{
public:
    ~DynamicArray() {
        cout<<"The array gets deleted with memory space ->"<<this<<endl;
    }
};
void helper() {
    DynamicArray a[2];
    cout<<"we are inside the helper"<<endl;
}
int main() {
    helper();
    cout<<"Deletion must have heppened by now."<<endl;
    return 0;

}