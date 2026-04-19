// Rewrite the shared counter increment example so that:

// The global counter is declared as std::atomic<int> counter{0};
// 5 threads each increment counter 1000 times (without any mutex or explicit locking)
// Join all threads and print the final result, confirming it is always 5000

#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int>count =0;

void write(){
    for(int i =0;i<100000;i++){
        count++;
    }
}

int main(){
    std::thread t1(write);
    std::thread t3(write);
    std::thread t4(write);
    std::thread t5(write);
    std::thread t6(write);

    t1.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    std::cout<<count<<std::endl;
    return 0;
    

}