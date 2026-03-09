// Creates a std::vector<int> v{1,2,3,4,5};
// Iterates over the vector using a for loop with auto for the iterator:
// for (auto it = v.begin(); it != v.end(); ++it)
// Prints the elements inside the loop

#include<iostream>
using namespace std;
int main(){
    vector<int> v{1,2,3,4,5};
    for(auto it : v){
        cout<<it;
    }
}