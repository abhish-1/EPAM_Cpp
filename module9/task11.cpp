// Defines a shared integer variable Launches several reader threads that repeatedly acquire a shared (read) lock and print the
// value Launches one writer thread that periodically acquires an exclusive (write) lock and updates the value Uses std::shared_mutex 
//to ensure:
// Multiple readers can read at the same time
// // Readers block while a writer holds the lock (and vice versa) Lets threads run for several iterations, demonstrating correct 
//synchronization

#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <vector>
#include <chrono>

int count = 0;
std::shared_mutex rwMutex;
std::mutex coutMutex;

void writer(int id) {
    for (int i = 0; i < 10; i++) {
        {
            std::unique_lock<std::shared_mutex> lock(rwMutex);
            count++;
            
            std::lock_guard<std::mutex> printLock(coutMutex);
            std::cout << "[Writer " << id << "] updated value to "<< count << " | thread: "<< std::this_thread::get_id() << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void reader(int id) {
    for (int i = 0; i < 10; i++) {
        {
            std::shared_lock<std::shared_mutex> lock(rwMutex);

            std::lock_guard<std::mutex> printLock(coutMutex);
            std::cout << "  [Reader " << id << "] reads value "<< count << " | thread: "<< std::this_thread::get_id() << "\n";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i <= 2; i++) {
        threads.emplace_back(writer, i);
    }
    for (int i = 1; i <= 5; i++) {
        threads.emplace_back(reader, i);
    }
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}