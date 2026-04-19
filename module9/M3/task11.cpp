// Declares a shared boolean flag (e.g., bool ready = false;), a std::mutex, and a std::condition_variable.
// Starts one thread ("waiter") that waits (using cv.wait()) until the flag becomes true.
// Starts another thread ("signaler") that sets the flag to true, then calls cv.notify_one() to wake the waiter thread.
// Demonstrates that the waiter only continues after being signaled.

#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

bool ready = false;
std::mutex m1;
std::condition_variable cv;

void waiter(){
    std::unique_lock<std::mutex> lock (m1);
    cv.wait( lock,[] {return ready;});
}
void signaler(){
    std::unique_lock<std::mutex> lock (m1);
    ready = true;
    cv.notify_one();
}

int main(){
    std::thread t1(waiter);
    std::thread t2(signaler);
    t1.join();
    t2.join();
    return 0;

}