// Write a C++ program that: Uses the shared counter example from previous tasks Protects the increment with std::lock_guard<std::
// mutex> in one thread function Uses std::unique_lockstd::mutex in another thread function Demonstrates that both achieve correct 
// results, but with different features Discusses when and why you might prefer one over the other
#include<iostream>
#include<thread>
#include<mutex>

int count =0;
std::mutex m1;

void increment(){
    for(int i =0;i<1000000;i++){
        std::unique_lock<std::mutex> m (m1);
        // - heavier than lock_guard
        // - flexible (can unlock manually, defer locking, try_lock, etc.)
        count++;
    }
}


void increment1(){
    for(int i =0;i<1000000;i++){
        std::lock_guard<std::mutex> m (m1);
        // - lightweight
        // - no flexibility (always locks immediately, unlocks on destruction)
        // - no manual unlock possible
        count++;
    }
    
}

int main(){
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout<<count<<std::endl;
    std::thread t3(increment1);
    std::thread t4(increment1);
    t3.join();
    t4.join();
    std::cout<<count<<std::endl;
}