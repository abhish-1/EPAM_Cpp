// Write a C++ program that: Creates a std::promise<int> object in main and retrieves its corresponding std::future<int> Launches a
//  thread that, after some delay, sets an integer value to the promise In the main thread, waits on the future and prints the value 
//  when it arrives
#include<thread>
#include<iostream>
#include<chrono>
#include<future>
void fun(std::promise<int> p){
    p.set_value(22);
}
int main(){

    std::promise<int> object;
    std::future<int> f = object.get_future();
    std::thread t1(fun, std::move(object));
    t1.join();

    std::cout<<f.get()<<std::endl;
}