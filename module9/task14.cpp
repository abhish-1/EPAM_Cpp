// Write a C++ program that: Defines a function longComputation() that sleeps for 2 seconds and then returns an int (e.g., 42) 
// Calls this function asynchronously using std::async Obtains the result using std::future::get() and prints it

#include<thread>
#include<iostream>
#include<chrono>
#include<future>

int longComputation(){
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return 42;
}

int main(){
    std::cout<<"Lets begin"<<std::endl;
    std::future<int> f = std::async(longComputation);
    std::cout<<"the thread has passed the async function"<<std::endl;
    std::cout<<f.get()<<std::endl;
    return 0;

}