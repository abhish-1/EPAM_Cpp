#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>

std::counting_semaphore<2> sig(2); 

void worker(int id) {
    std::cout << "Thread " << id << " is waiting...\n";
    sig.acquire(); // Decrement counter
    
    std::cout << "Thread " << id << " entered the room!\n";
    std::this_thread::sleep_for(std::chrono::seconds(4)); // Simulate work
    
    std::cout << "Thread " << id << " is leaving.\n";
    sig.release(); // Increment counter
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(worker, i);
    }
    for (auto& t : threads) t.join();
    return 0;
}