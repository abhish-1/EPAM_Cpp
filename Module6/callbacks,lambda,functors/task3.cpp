// Modifies invokeCallback to accept std::function<void(const std::string&)> as the callback argument
// Passes both a regular function and a lambda expression as callbacks to invokeCallback
// Prints outputs to confirm both are accepted and invoked correctly

#include<iostream>
#include<functional>
using namespace std;
void greetMorning(const std::string& name) {
    std::cout << "Good morning, " << name << "!" << std::endl;
}
void greetEvening(const std::string& name) {
    std::cout << "Good evening, " << name << "!" << std::endl;
}
void invokeCallback(std::function<void(const std::string& name)>) {
    callback(name);
}

int main() {
    invokeCallBack(greetEvening("abhishek"));
    invokeCallBack([](const String& str)->{
        greetEvening(name);
    });
    return 0;
}