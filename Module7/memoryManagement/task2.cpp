// Part A: Create the Logger Class
// Design a Logger class with:
// A constructor that takes a std::string name parameter and prints creation message
// A log() method that prints messages in format: [LoggerName]: message
// A close() method that marks the logger as inactive and prints a closing message
// A destructor that calls close() and prints a destruction message
// A getName() method to retrieve the logger's name
// Private members: name (string) and isOpen (boolean, default value is ture and will be false while closing)
// Part B: Implement Main Function Demonstrations

// In main(), create a series of demonstrations using std::unique_ptr:
// Basic Creation: Create your first logger using std::make_unique and log a message std::unique_ptr<Logger> logger = std::make_unique<Logger>("MainLogger"); logger->log("Hello from MainLogger");
// Assignment Replacement: Assign a new logger to the same pointer, observing the old one's destruction logger = std::make_unique<Logger>("SecondaryLogger"); logger->log("Hello from SecondaryLogger");
// Reset with New Object: Use reset() with a new Logger object logger.reset(new Logger("TemporaryLogger")); logger->log("I replaced the previous logger");
// Reset to Null: Use reset() without arguments and check if pointer is null logger.reset(); std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << "\n";
// Null Assignment: Assign nullptr to the pointer logger = nullptr;
// Reassignment: Create a new logger after null state logger = std::make_unique<Logger>("NewLogger"); logger->log("Back in business");
// Move Semantics: Create a second pointer and move its ownership to the first auto logger2 = std::make_unique<Logger>("Logger2"); logger = std::move(logger2); logger->log("Now I own Logger2's resource"); std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";
// Self-Move: Attempt to move the pointer to itself logger = std::move(logger); // Self-assignment logger->log("Self-move didn't destroy me!");

#include <iostream>
#include <string>
#include <memory>

using namespace std;
class Logger{
    string name;
    bool isOpen= true;
    public:
    Logger(const string& name): name(name){
        cout<<"Logger constructed"<<endl;
    }
    void log(const std::string& message){
    if(isOpen){
        cout << "[" << name << "]: " << message << "\n";
    }
}
    void close(){
    if(isOpen){
        isOpen = false;
        cout << "Logger '" << name << "' closing.\n";
    }
}

    ~Logger(){
        close();
        cout<<"destructor"<<endl;
    }
    void getName(){
        cout<<name<<endl;
    }
};
int main(){
    std::unique_ptr<Logger> logger = std::make_unique<Logger>("MainLogger"); 
    logger->log("Hello from MainLogger");
    logger = std::make_unique<Logger>("SecondaryLogger"); 
    logger->log("Hello from SecondaryLogger");
    logger.reset(new Logger("TemporaryLogger")); logger->log("I replaced the previous logger");
    logger.reset(); std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << "\n";
    logger = std::make_unique<Logger>("NewLogger"); logger->log("Back in business");
    auto logger2 = std::make_unique<Logger>("Logger2"); logger = std::move(logger2); logger->log("Now I own Logger2's resource"); std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";
    logger = std::move(logger);
    logger->log("Self-move didn't destroy me!");
}