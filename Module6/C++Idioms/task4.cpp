// Declares a shared int counter = 0; and a std::mutex mtx;
// Defines a function that increments the counter, protecting it with std::lock_guard<std::mutex>
// Launches multiple threads calling this function repeatedly
// (Optionally) Throws an exception in the increment function to demonstrate that the mutex is automatically released
// After joining all threads, prints the final value and observes no deadlocks

#include<iostream>
#include<thread>
#include<vector>
using namespace std;

int count = 0;

void increment() {
    count++;   // same hi rakha
}

int main(){
    vector<thread> threads;

    for(int i = 0; i < 10000; i++){
        threads.push_back(thread(increment));  // create threads
    }

    for(auto &t : threads){
        t.join();  // join baad me
    }

    cout << count;
}