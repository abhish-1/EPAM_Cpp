#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const int MAX_SIZE = 10;

std::mutex m;
std::condition_variable cv;

void producer() {
    for(int i = 0; i < 100; i++) {
        std::unique_lock<std::mutex> lock(m);

        // wait until buffer has space
        cv.wait(lock, [] { return buffer.size() < MAX_SIZE; });

        buffer.push(i);
        std::cout << "Produced: " << i << "\n";

        cv.notify_one(); // consumer ko jagao
    }
}

void consumer() {
    for(int i = 0; i < 100; i++) {
        std::unique_lock<std::mutex> lock(m);

        // wait until buffer has data
        cv.wait(lock, [] { return !buffer.empty(); });

        int val = buffer.front();
        buffer.pop();

        std::cout << "Consumed: " << val << "\n";

        cv.notify_one(); // producer ko jagao
    }
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();
}