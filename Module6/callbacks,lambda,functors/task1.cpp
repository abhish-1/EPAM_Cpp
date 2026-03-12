// Defines a function: void greet(const std::string &name) that prints a greeting with the name
// Defines a function: void invokeCallback(void (*callback)(const std::string&), const std::string &name) that receives a function pointer and a name, and calls callback(name)
// In main(), passes greet to invokeCallback and supplies a name, printing the greeting

#include<iostream>
using namespace std;
void greet(const std::string &name){
    cout<<"Hey "<<name <<" what's up"<<endl;
}
void invokeCallback(void (*callback)(const std::string&), const std::string &name){
    cout<<"Inside invokecallback"<<endl;
    callback(name);
    cout<<"callback complete, back to invokeCallBack"<<endl;

}
int main(){
    invokeCallback(greet,"abhishek");
    return 0;

}