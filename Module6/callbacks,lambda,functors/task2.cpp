// Defines two separate functions: void greetMorning(const std::string&) and void greetEvening(const std::string&), each printing a different greeting message.
// Uses an existing or new invokeCallback function: void invokeCallback(void (*callback)(const std::string&), const std::string&).
// Passes both greeting functions as callbacks to invokeCallback with sample names.
// Observes that the code calls the correct variant, demonstrating callback flexibility.
#include<iostream>
using namespace std;
void greetMorning(const std::string& name) {
    std::cout << "Good morning, " << name << "!" << std::endl;
}
void greetEvening(const std::string& name) {
    std::cout << "Good evening, " << name << "!" << std::endl;
}
void invokeCallback(void (*callback)(const std::string&), const std::string& name) {
    callback(name);
}

int main() {
    invokeCallback(greetMorning, "Abhish1");
    invokeCallback(greetEvening, "Suyash");
    return 0;
}
