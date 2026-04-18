// Thread A prints odd numbers (1, 3, ... 19)
// Thread B prints even numbers (2, 4, ... 20) Coordinates their execution so the output is: 1 2 3 4 ... 19 20 
// \(in order) Employs a shared counter, std::mutex, and std::condition_variable to alternate control between threads

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex m;
std::condition_variable cv;
int i = 1;

void odd(){
    for(; i<20; ){
        std::unique_lock<std::mutex> lock (m);
        cv.wait(lock,[](){return i%2==1;});
        std::cout<<i<<std::endl;
        i++;
        cv.notify_one();
    }
}

void even(){
    for(; i<=20; ){
        std::unique_lock<std::mutex> lock( m);
        cv.wait(lock,[](){return i%2==0;});
        std::cout<<i<<std::endl;
        i++;
        cv.notify_one();
    }
}

int main(){
    std::thread t1(odd);
    std::thread t2(even);
    t1.join();
    t2.join();
    return 0;
}