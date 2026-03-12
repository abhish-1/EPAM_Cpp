// Defines int factor = 3;
// Applies std::for_each to a vector with a lambda that captures factor by value ([factor](int &x){ x *= factor; })
// Prints the modified vector
// Changes factor and applies std::for_each again with a lambda that captures by reference ([&factor](int &x){ x *= factor; })
// Prints results and discusses effects

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    int factor =3;
    vector<int> vec {1,2,3,4,5};
    for_each(vec.begin(),vec.end(),[&factor](int&x)->void{
        x *= factor;
    });
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    
    for_each(vec.begin(),vec.end(),[&factor](int &x)-> void{ 
        x *= factor; 
    });
    for(int i = 0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    
}