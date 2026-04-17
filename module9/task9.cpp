// Write a C++ program that: Defines a class Logger with:
// Private constructor
// Deleted copy constructor and copy assignment
// A static method getInstance() returning a reference to the single instance
// Spawns several threads, each calling Logger::getInstance() and possibly performing an action (e.g., log or print address) Confirms,
// via output, that all threads use the same Logger instance
#include<iostream>
#include<thread>
class Logger{
    Logger(){
        std::cout<<"obj created"<<std::endl;
    }
    public:
    Logger(const Logger& l) = delete;
    Logger& operator= (const Logger& l)= delete;
    static Logger& getInstance (){
        static Logger l;
        std::cout<<&l<<std::endl;
        return l;
    }
    void log(const std::string& message) {
        std::cout << "[Thread " << std::this_thread::get_id() << "] " << message << "\n";
    }
};

int main(){
    auto threadFunc = []() {
        Logger& logger = Logger::getInstance();
        // Log a message including thread ID
        logger.log("Logging from thread");
        // Print singleton address
        std::cout << "Singleton address: " << &logger << "\n";
    };

    std::thread t1(Logger::getInstance);
    std::thread t2(Logger::getInstance);
    std::thread t3(Logger::getInstance);
    std::thread t4(Logger::getInstance);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

}