// Defines int counter = 0;
// Defines a lambda: auto next = [counter]() mutable { counter++; return counter; };
// Calls next() multiple times and prints results
// Prints the value of counter in the outer scope to demonstrate that the lambda’s internal state is independent of the original variable

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Square {
    void operator()(int& x) const { x *= x; }
};
int main(){
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{1, 2, 3, 4, 5};
    

    for_each(v1.begin(),v1.end(), Square( ));
    for_each(v2.begin(),v2.end(),[](int& x) { x *= x; });

    for(int i =0;i<v1.size();i++){
      cout<<v1[i]<<endl;
    }
for(int i =0;i<v1.size();i++){
      cout<<v2[i]<<endl;
    }
}