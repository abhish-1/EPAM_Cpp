// Defines a MyString class with both copy and move constructors (and proper destructor)
// Writes a function MyString makeString() that returns a MyString by value
// Assigns the function's return value to another object in main
// Prints diagnostic messages in constructors to observe whether the copy or move constructor is called
#include<iostream>
#include<utility>
using namespace std;
class MyString{

    int* data;
    int size;  
public:
    MyString(int s) : size(s) {  // Store the size
        cout<<"constructor gtes called"<<endl;
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = i * 11;
    }
    
    ~MyString() {
        delete[] data;
    }
    
    MyString(MyString& other) : size(other.size) {  // Copy the size
        cout<<"copy constructor"<<endl;
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    MyString(MyString&& other) : size(other.size) {  // Copy the size
        cout<<"move constructor"<<endl;
        if(this!=&other){
            data = other.data;
            size=other.size;
            other.data=nullptr;
            other.size=0;
        } 
    }
    
    void print() {
        for(int i = 0; i < size; i++) {  // Use the stored size
            cout << data[i] << endl;
        }
    }
};
MyString makeString(int x){
    MyString a(x);
    return a;

}
int main(){
    MyString mc = makeString(5);

}
    MyString(MyString&& other) : size(other.size) {  // Copy the size
        cout<<"move constructor"<<endl;
        if(this!=&other){
            data = other.data;
            size=other.size;
            other.data=nullptr;
            other.size=0;
        } 
    }
    
    void print() {
        for(int i = 0; i < size; i++) {  // Use the stored size
            cout << data[i] << endl;
        }
    }
};
MyString makeString(int x){
    MyString a(x);
    return a;

}
int main(){
    MyString mc = makeString(5);

}