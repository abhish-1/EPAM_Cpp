#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <stdexcept>
using namespace std;

class MyException: public exception{
    string message;
    public:
    explicit MyException(string message): message(message){
    }
    MyException():message(""){
    }
    const char* what() noexcept{
        return message.c_str();
    }
};
class MyException1: public MyException{
    string message1;
    public:
    MyException1(string message1): message1(message1){
    }
    const char* what() noexcept{
        return message1.c_str();
    }
};

int main() {

    try{
        throw MyException1("ouch");
    }
    catch(MyException& e){
        cout<<"nigg"<<endl;
    }
}