// Defines a class Numbers with a constructor: Numbers(std::initializer_list<int> list)
// Stores the elements in a private std::vector<int>
// Prints the stored elements using a range-based for loop

#include<iostream>
class Numbers{
    std::vector<int>vec;
    public:
    Numbers(std::initializer_list<int> list) {
        for(auto it:list){
            vec.push_back(it);
        }
    }
    void print(){
        for(auto it:vec){
            cout<<it;
        }
    }

}
int main(){
    vector<int> vec {10,11,12,13,14,15};
    Numbers N(vec);
    N.print();

}