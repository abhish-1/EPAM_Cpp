// mt_crash.cpp
#include <iostream>
#include <thread>
#include <chrono>

int* shared_ptr = nullptr;

void writer() {
    shared_ptr = new int(42);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    delete shared_ptr;
    shared_ptr = nullptr;
}

void reader() {
    for (int i = 0; i < 10; ++i) {
        //if (shared_ptr) {
            // Potentially dereferencing after delete!
            std::cout << "Read value: " << *shared_ptr << std::endl;
        //}
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    std::thread t1(writer);
    std::thread t2(reader);
    t1.join();
    t2.join();
    return 0;
}
