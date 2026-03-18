// Write a C++ program that:
// Defines a class ResourceHolder which manages dynamic memory (e.g., int* data)
// Implements:
// A constructor allocating memory
// A copy constructor (deep copy)
// A copy assignment operator (deep copy, self-check, proper cleanup)
// A destructor (releases memory)
// Tests all copy operations in main
// Uses print statements to show actions and memory addresses to confirm correctness
// Checks for leaks via Valgrind or by visual inspection (no double deletes or lost memory)
#include<iostream>
#include<utility>
using namespace std;
class ResourceHolder {
    int* data;
    int size;  // Add this member to track the size
public:
    ResourceHolder(int s) : size(s) {  // Store the size
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = i * 11;
    }
    
    ~ResourceHolder() {
        delete[] data;
    }
    
    ResourceHolder(ResourceHolder& other) : size(other.size) {  // Copy the size
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    ResourceHolder& operator=(ResourceHolder& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;  // Copy the size
            data = new int[size];
            for(int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    void print() {
        for(int i = 0; i < size; i++) {  // Use the stored size
            cout << data[i] << endl;
        }
    }
};
int main(){
    ResourceHolder r(5);
    cout<<"copy"<<endl;
    ResourceHolder p(r);
    r.print();
    cout<<endl;
    p.print();
    ResourceHolder a(5);
    a.print();
    a=r;
    r.print();
    a.print();
    


}