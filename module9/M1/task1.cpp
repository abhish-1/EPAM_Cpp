// define the Worker Function

// Write void printMessage(const std::string &msg)
// Inside, print the message and std::this_thread::get_id() to indicate which thread printed it.
// Launch Multiple Threads

// In main, create a vector (or array) of std::thread objects.
// For each thread, instantiate with printMessage and a unique message.
// Join All Threads

// Iterate through your thread container and call join() on each thread object to wait for their termination before exiting the program.
#include<iostream>
#include<vector>
#include<thread>
#include<chrono>
#include<mutex>

void printMessage(const std::string &msg){
    std::cout<<msg<<std::endl;
    std::cout<<"The thread in here has id "<< std::this_thread::get_id()<<std::endl;

}

int main(){
    std::vector<std::thread> vec;
    vec.emplace_back(printMessage,"this is the first thread");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    vec.emplace_back(printMessage,"this is the second thread");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    vec.emplace_back(printMessage,"this is the third thread");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    vec.emplace_back(printMessage,"this is the fourth thread");

    for(auto it:vec){
        it.join();
    }
}


