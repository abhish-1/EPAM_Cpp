// Defines a MyString class with a move constructor and a print method showing the internal data address
// Writes a function void printAddress(MyString&& s) which prints the object’s internal buffer address
// Demonstrates calling printAddress(std::move(obj)) and printAddress(MyString("temp"))
// Implements a template function template<typename T> void forwardToPrint(T&& str) that forwards its argument to printAddress using std::forward<T>(str)
// Calls forwardToPrint with both lvalues and rvalues, comparing behavior and constructor calls

#include<iostream>
#include<utility>
#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

class MyString {
    char* data;
public:
    MyString(const char* str) {
        cout<<"constructor"<<endl;
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructed: " << data << " at " << static_cast<const void*>(data) << "\n";
    }
    MyString(const MyString& other) {
        cout<<"Copy constructor"<<endl;
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
        std::cout << "Copied: " << data << " at " << static_cast<const void*>(data) << "\n";
    }
    MyString(MyString&& other) noexcept : data(other.data) {
        cout<<"move constructor"<<endl;
        other.data = nullptr;
        std::cout << "Moved! at " << static_cast<const void*>(data) << "\n";
    }
    ~MyString() {
        cout<<"destructor"<<endl;
        std::cout << "Destructed " << (data ? data : "null") << " at " << static_cast<const void*>(data) << "\n";
        delete[] data;
    }
    void printAddress() const {
        std::cout << static_cast<const void*>(data) << std::endl;
    }
};

void printAddress(MyString&& s) {
    std::cout << "printAddress receives buffer" <<endl;
    s.printAddress();
}


template<typename T>
void forwardToPrint(T&& str){
    printAddress(forward<T>(str));

}
int main() {
    MyString obj1("apple");
    forwardToPrint(move(obj1));
    forwardToPrint(MyString("mango"));

    
} 