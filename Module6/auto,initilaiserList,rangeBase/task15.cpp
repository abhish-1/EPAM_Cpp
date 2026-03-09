// Defines a class Matrix with a constructor accepting std::initializer_list<std::initializer_list<int>>
// Stores the matrix internally as std::vector<std::vector<int>>
// Provides a method (e.g., std::vector<std::vector<int>>) that uses nested range-based loops with auto& row and auto& col to:
// Print all elements
// Double each value (in-place modification)
// Prints the matrix again after modification to show the changes

#include<iostream>
#include <vector>
#include<initializer_list>
using namespace std;
class Matrix{
    vector<vector<int>> mat;
    public:
    Matrix(initializer_list<std::initializer_list<int>> temp): mat(temp){}
    void print(){
        for(auto& it: mat){
            for(auto& i:it){
                cout<<i<<endl;
                i=i*2;
            }
        }
        for(const auto& it: mat){
            for(const auto& i:it){
                cout<<i<<endl;
            }
        }
    }
};
int main(){
    Matrix mat{{1, 2},{3, 4}};
    mat.print();
    return 0;

}