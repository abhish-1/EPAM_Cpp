// Write a C++ program that: Creates two std::mutex objects
// Starts two threads which attempt to lock both mutexes, but in opposite order (to simulate deadlock)
// Demonstrates the deadlock by noting that both threads get stuck
// Fixes the code by replacing the locking with std::lock() (or std::scoped_lock in C++17), ensuring both mutexes are acquired atomically
// without deadlock

#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>

std::mutex m1;
std::mutex m2;

void fun1(){
    std::scoped_lock lock(m1,m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout<<"I am not reaching here"<<std::endl;
}

void fun2(){
    std::scoped_lock lock(m1,m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::cout<<"I am not reaching here"<<std::endl;
}

int main(){
    std::thread t1(fun1);
    std::thread t2(fun2);
    t1.join();
    t2.join();
    std::cout<<"Completed with the program"<<std::endl;
    return 0;
}


