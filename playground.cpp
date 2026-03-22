#include <iostream>
#include <memory>
#include<typeinfo>
using namespace std;

void getDataonPointer(const unique_ptr<int>& ptr){
    cout<<typeid(ptr).name()<<endl;
    cout<<ptr.get()<<endl;
    cout<<*ptr<<endl;
    cout<<&ptr<<endl;
}


int main() {
    unique_ptr<int> ptr(new int(10));
    getDataonPointer(ptr);
    unique_ptr<int> ptrCopy = move(ptr);
    //getDataonPointer(ptr);
    cout<<endl<<endl;
    getDataonPointer(ptrCopy);
}