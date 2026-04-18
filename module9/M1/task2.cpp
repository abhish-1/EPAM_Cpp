// Define Worker Function

// Implement void worker(), which calls std::this_thread::sleep_for(std::chrono::seconds(2)); and then prints its ID and a completion message.
// Start and Detach Thread

// In main, create a std::thread with worker as the task.
// Immediately call .detach() on the thread object (e.g., t.detach();).
// Immediate Main Exit

// Right after detaching, print "main ends" to show that main may end before the worker thread.

#include<iostream>
#include<thread>
void worker(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"The id of this thread is "<<std::this_thread::get_id()<<std::endl;
    std::cout<<"Completed task"<<std::endl;
}
int main(){
    std::thread t(worker);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Prog over"<<std::endl;

}