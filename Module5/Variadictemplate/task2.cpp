// Task:
// Write a C++ program that:
// Defines a template class MyTuple as template<typename... Args> class MyTuple
// Stores the argument values (either as member variables using inheritance or, more simply, by using an internal std::tuple<Args...> data)
// Provides a constructor to initialize all elements
// Provides a method to print all elements (you can leverage std::get<N>(data) and a helper function for recursive printing)
// Demonstrates usage with MyTuple<int, double, std::string> t(1, 2.5, "hello"); and prints its elements

#include<iostream>
#include<tuple>
using namespace std;
template<typename... Args>
class MyTuple {
    std::tuple<Args...> data;
public:
    MyTuple(Args... args) : data(args...) {}

    void print() const {
        printHelper<0>();
        std::cout << std::endl;
    }
private:
    template<std::size_t Index>
    void printHelper() const {
        if constexpr (Index < sizeof...(Args)) {
            std::cout << std::get<Index>(data) << " ";
            printHelper<Index + 1>();
        }
    }
};
int main(){
    Tuple<int,double,string>(45,12.34,"apple");
    return 0;
}