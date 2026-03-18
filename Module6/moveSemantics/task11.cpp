// Defines a class MyString with both copy and move constructors (with diagnostic messages)
// Creates a std::vector<MyString>
// Adds objects using push_back(obj), push_back(std::move(obj)), and emplace_back("temp")
// Observes and prints which constructors are called for each operation
#include<iostream>
#include<utility>
#include <iostream>
#include <cstring>
#include <utility>
#include<vector>
class MyString {
    char* data;
public:
    explicit MyString(const char* str) {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructed: " << data << " at " << static_cast<const void*>(data) << "\n";
    }
    MyString(const MyString& other) {
        std::cout<<"Copy constructor"<<std::endl;
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
        std::cout << "Copied: " << data << " at " << static_cast<const void*>(data) << "\n";
    }
    MyString(MyString&& other) noexcept : data(other.data) {
        std::cout<<"move constructor"<<std::endl;
        other.data = nullptr;
        std::cout << "Moved! at " << static_cast<const void*>(data) << "\n";
    }
    ~MyString() {
        std::cout << "Destructed " << (data ? data : "null") << " at " << static_cast<const void*>(data) << "\n";
        delete[] data;
    }
    void printAddress() const {
        std::cout << static_cast<const void*>(data) << std::endl;
    }
};
int main(){
    std::vector<MyString> vec;
    
    //MyString obj("apple");
    // std::cout<<"pushback soon"<<std::endl<<std::endl;
    // vec.push_back(obj);
    // std::cout<<"pushback with move"<<std::endl;
    //vec.push_back(std::move(obj));
    // std::cout<<"emplace back"<<std::endl;
     vec.emplace_back("mango");
}