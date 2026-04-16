// // Uses std::queue<int> as a shared buffer between threads Launches one producer thread to push numbers 1 through 20
// into the queue (with locking) Launches one consumer thread to pop and print numbers from the queue Uses std::mutex to 
// guard the queue and std::condition_variable to signal when the queue becomes
//  non-empty Continues until all numbers are produced and consumed\\\
#include <iostream>

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> q;
std::mutex m;
std::condition_variable cv;

bool done = false; 
void producer() {
    for(int i = 1; i <= 20; i++) {
        std::unique_lock<std::mutex> lock(m);

        q.push(i);
        std::cout << "Produced: " << i << "\n";

        cv.notify_one();
    }

    // signal completion
    std::unique_lock<std::mutex> lock(m);
    done = true;
    cv.notify_one();
}

void consumer() {
    while(true) {
        std::unique_lock<std::mutex> lock(m);

        cv.wait(lock, [] { return !q.empty() || done; });

        if(q.empty() && done)
            break;

        int val = q.front();
        q.pop();

        std::cout << "Consumed: " << val << "\n";
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}