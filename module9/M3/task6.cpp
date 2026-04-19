// Creates a shared std::string Launches one writer thread that modifies the string (e.g., appends characters or replaces value in a loop) Launches 
// multiple reader threads that read and print the string repeatedly in their own loops Protects all read/write access using std::shared_mutex:
// Writer uses std::unique_lock<std::shared_mutex>
// Each reader uses std::shared_lock<std::shared_mutex> Demonstrates that, with proper locking, race conditions and crashes are avoided

#include<iostream>
#include<mutex>
#include<shared_mutex>

#include<thread>
#include<string>

//std::shared_mutex m1;
std::string str = "abcd";

void write(){
    for(int i =0;i<10;i++){
        //std::unique_lock<std::shared_mutex> lock (m1);
        str+=std::to_string(i);
        std::cout<<str<<std::endl;
    }
}

void read(){
    for(int i =0;i<10;i++){
        //std::shared_lock<std::shared_mutex> lock (m1);
        std::cout << str << std::endl;
        std::cout<<"thread id "<<std::this_thread::get_id<<std::endl;
    }
}

int main(){
    std::thread t1(write);
    std::thread t2(read);

    t1.join();
    t2.join();

    return 0;
    

}