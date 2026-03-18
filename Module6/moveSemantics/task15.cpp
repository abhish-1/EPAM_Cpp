// Defines a class ModernResource using only STL types (e.g., std::vector, std::unique_ptr, std::string)
// Does not declare or define any destructor, copy/move constructor, or assignment operators (relies on compiler defaults — Rule of 0)
// Demonstrates creating, copying, moving, and assigning ModernResource objects and shows that all operations are safe and resource leaks are prevented
// Optionally includes a manual resource-owning class with full Rule of 5, for comparison
// Briefly discusses the merits of the Rule of 0 and RAII in a comment block

#include<iostream>
#include<vector>
#include<string>
#include <memory>
using namespace std;
class ModernResource{
    vector<int> vec;
    unique_ptr<int> ptr3 ;
    string str;
    public:
    ModernResource(vector<int> vec,unique_ptr<int> ptr3,string str):vec(vec),ptr3(move(ptr3)),str(str){
        cout<<"Basic consrtructor "<<endl;
    }
    void print() const {
        std::cout << str << ":";
        for (int x : vec) std::cout << " " << x<<endl;
        if(ptr3!=nullptr)std::cout<<ptr3 << std::endl;
    }
};

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5, 6};
    unique_ptr<int> ptr3(new int(32));
    string str1 = "apple";
    
    ModernResource m1(std::move(vec1), std::move(ptr3), std::move(str1));
    //the following below ones will give an error as you try to copy the uniq pointer.
    // ModernResource m2(m1);              
    // ModernResource m3 = std::move(m1);   
    // ModernResource m4 = m3;      
    
    return 0;
}