// Defines a class MyString with a char* member.Implements A constructor that allocates memory and copies a passed C-string.
// A copy constructor that allocates new memory and copies the passed object's string (deep copy).
// In main, creates a MyString object, copies it to another, and prints the memory addresses of the internal strings to verify separate allocation.

//task2
// Extends the previous MyString class to implement the copy assignment operator (operator=)
// Performs deep copy: correctly duplicates the data and manages the old memory
// In main, assigns one MyString object to another and prints contents and internal memory addresses to verify a deep, not shallow, copy

// Defines a class MyString with a char* member.Implements A constructor that allocates memory and copies a passed C-string.
// A copy constructor that allocates new memory and copies the passed object's string (deep copy).
// In main, creates a MyString object, copies it to another, and prints the memory addresses of the internal strings to verify separate allocation.

//task2
// Extends the previous MyString class to implement the copy assignment operator (operator=)
// Performs deep copy: correctly duplicates the data and manages the old memory
// In main, assigns one MyString object to another and prints contents and internal memory addresses to verify a deep, not shallow, copy

#include<iostream>
#include<utility>
#include<cstring>
using namespace std;
class MyString{
    char* data;
    public:
    MyString(const char* str){
        data = new char[strlen(str)+1];
        strcpy(data,str);
    }
    MyString(const MyString& other){
        cout<<"copy const"<<endl;
        data = new char[strlen(other.data)+1];
        strcpy(data,other.data);
    }
    MyString& operator=(const MyString& other){
        if(this!=&other){
            delete[]data;
            data = new char[strlen(other.data)+1];
            strcpy(data,other.data);
            return *this;     
        }
        cout<<"Copy Assig"<<endl;
    }

    MyString(MyString&& other)noexcept{
        cout<<"move assignment"<<endl;
        data=other.data;
        other.data=nullptr;

    }

    MyString& operator=(MyString&& other) noexcept {
        cout<<"Move assignment"<<endl;
        if(this!=&other){
            delete [] data;
            data=other.data;
            other.data=nullptr;
           
        }
        return *this;

    }
        
    void print() const {
        std::cout << "String: " << data
                  << " (at: " << static_cast<const void*>(data) << ")\n";
    }
    ~MyString(){
        delete[] data;
    }
  

};
  


int main() {
    MyString s1("hello");
    MyString s2 = s1;
    s1.print();
    s2.print();
    return 0;
}