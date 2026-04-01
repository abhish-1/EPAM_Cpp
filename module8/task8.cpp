#include<iostream>
#include<list>
#include<string>
#include<iomanip>
#include<chrono>

using namespace std;
struct Task{
    string name;
    int priority;
    int deadline;
    void print(){
        cout<<"Task: "<<name<<", Priority: "<<priority<<", Deadline: "<<deadline<<endl;
    }
};
bool predicate(const Task&a, const Task&b){
    if(a.priority == b.priority){
        return a.deadline < b.deadline;
    }
    return a.priority < b.priority;
}
int main(){
    list<Task> tasks = { {"Sending the Mail", 2, 5}, {"Fix Critical bug", 1, 1}, {"Team meeting", 2, 1}, {"Code review", 2, 3}, {"Update docs", 3, 4} };
    for (auto& task : tasks) {
        task.print();
    }
    tasks.sort(predicate);
    cout<<"After sorting by priority and deadline:"<<endl;
    for (auto& task : tasks) {
        task.print();
    }
}
