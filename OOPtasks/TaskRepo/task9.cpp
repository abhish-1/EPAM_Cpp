//Defines a Logger class with data members: mutable int accessCount and std::string message
//Implements a print() member function marked const, which increments accessCount and prints
//message. Demonstrates that mutable allows modification of accessCount inside the const
//function Prints accessCount before and after calling print() to show the change

#include<iostream>
class Logger {
    mutable int accessCount=0;
    std::string message = "AccessCount is mutable and I will hange it from a const funxtion\n";
public:
    void print() const {
        accessCount++;
        std::cout<<message;
    }
    void confirmation() {
        std::cout<<accessCount<<std::endl;
    }
};
int main() {
    Logger log;
    log.confirmation();
    log.print();
    log.confirmation();
    return 0;
}