#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int counter = 0;
std::mutex m;

void work() {
    for (int i = 0; i < 1000; i++) {
        std::lock_guard<std::mutex> lock(m);
        counter++; // protected
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; i++) {
        threads.emplace_back(work);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter = " << counter << std::endl;
    std::cout << "Expected = 5000" << std::endl;

    return 0;
}