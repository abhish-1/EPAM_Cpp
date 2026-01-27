//Write a C++ program that: Defines a DynamicArray class containing a pointer to a dynamically allocated int array (int* data)
//Implements a default constructor that allocates memory Implements a destructor that frees allocated memory. Implement a
//copy constructor that performs a deep copy (allocates new memory and copies contents) Demonstrates usage of compiler-generated
//(default) copy constructor for comparison (shows shallow copy issues) Prints appropriate messages to observe copying and destruction
//behavior
#include<iostream>
using namespace std;
class DynamicArray {
    int* data;
    int size;
public:
    DynamicArray(int n) {
        data = new int[n];
        size = n;
        cout<<"The arr has been created with the name data"<<endl;
    }
    ~DynamicArray() {
        delete[] data;
    }
    DynamicArray(const DynamicArray& other) {
        data = new int[other.size];
        for (int i =0;i<other.size;i++) {
            data[i]= other.data[i];
        }
    }
    void set(int index, int value) {
        data[index] = value;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicArray a(3);
    a.set(0,0);
    a.set(1,1);
    a.set(2,2);

    DynamicArray b = a;

    b.print();
    a.print();
}
