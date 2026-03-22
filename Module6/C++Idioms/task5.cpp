// Defines a Timer class:
// Constructor starts a high-resolution timer.
// Destructor prints the elapsed time in milliseconds or microseconds.
// // Uses the Timer object at the start of a code scope (e.g., inside a loop or function) to automatically measure duration.
#include<iostream>
#include<chrono>
#include <iomanip>
class Timer{
    std::chrono::time_point<std::chrono::high_resolution_clock> a;  // 2️⃣ Proper type!
    public:
    Timer(){
        std::cout<<"Constructor called"<<std::endl;
        a = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        std::cout<<"destructor called"<<std::endl;
        auto b = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(b - a);
        std::cout << "Time: " << duration.count() << " μs\n";
    }
};
int main(){
    {
        Timer();
    }
    std::cout<<"main function to end";
    return 0;
}