// Defines a variadic template function sumAll which returns the sum of all its arguments.
// Implements it using a fold expression:
// return (args + ...);
// Tests the function, e.g. sumAll(1, 2, 3, 4.5).
// Optionally compares with a recursive template implementation approach.

#include<iostream>
using namespace std;
template<typename...Args>
int sumAll(Args... args){
    int sum = 0;
    ((sum+=args), ...);
    return sum;
}

//template<>
int sum(){
    return 0;
}
template<typename first,typename... Rest>
int sum(first f,Rest... rest ){
    return f+sum(rest...);
}
int main(){
    cout<<sumAll(1,2,33)<<endl;
    cout<<sum(43,56,75);
}