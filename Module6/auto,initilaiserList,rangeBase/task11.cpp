// Defines a Numbers class as in the previous task, with public or member-accessible list (such as a std::vector<int> data member)
// Initializes a Numbers nums{1, 2, 3, 4, 5};
// Uses for(auto x : nums.list) (or for(auto x : nums.data)) in main() to print the elements
// Observes how type deduction works for elements in the loop

#include<iostream>
class Numbers{
    public:
    std::vector<int> data;
    Number(std::initialiser_list<int> list):data(list){}
};
int main(){
    Number N(list);
    std::initialiser_list<int> list {1,2,3,4,5,6,7,8,9};
    for(auto x: N.data){
        std::x<<endl;
    }
}