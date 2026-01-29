//Defines a class LeakDemo with constructor and destructor printing messages (class LeakDemo)
//Executes a loop (e.g., 1,000 iterations) allocating a new LeakDemo object each time
//(LeakDemo* obj = new LeakDemo) Does NOT free memory inside the loop initially
//(i.e., no delete) Runs the program and observes memory consumption (use system/task
//manager or leak checker tools) Fixes the memory leak by adding delete statement in
//the loop (delete obj) Verifies memory usage or checks with a leak checker after the fix

#include<iostream>
using namespace std;
class LeakDemo {
public:
    LeakDemo() {
        cout<<"New object is created"<<endl;
    }
    ~LeakDemo() {
        cout<<"object is deleted"<<endl;
    }
};
int main() {
    for (int i =0;i<1000;i++) {
        LeakDemo* obj = new LeakDemo{};
        delete(obj);
    }
}