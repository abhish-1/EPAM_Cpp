// Write a C++ program that: Defines a shared buffer between threads (use std::optional<int> as the single-slot buffer) 
//Starts a producer thread that generates numbers 1–10, waits for buffer to be empty, then produces the next number Starts
// a consumer thread that waits for buffer to be full, consumes (prints) the value, and then empties the buffer Uses 
//std::condition_variable to signal between producer and consumer whenever buffer transitions between empty/full
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <optional>

std::optional<int> buffer; 
std::mutex m;
std::condition_variable cv;

void producer() {
    for(int i = 1; i <= 10; i++) {
        std::unique_lock<std::mutex> lock(m);

        // wait until buffer is empty
        cv.wait(lock, [] { return !buffer.has_value(); });

        buffer = i;
        std::cout << "Produced: " << i << "\n";

        cv.notify_one();
    }
}

void consumer() {
    for(int i = 1; i <= 10; i++) {
        std::unique_lock<std::mutex> lock(m);

        // wait until buffer has value
        cv.wait(lock, [] { return buffer.has_value(); });

        int val = *buffer;
        buffer.reset(); // empty it

        std::cout << "Consumed: " << val << "\n";

        cv.notify_one();
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}