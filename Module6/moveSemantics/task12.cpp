// Defines a LargeArray class with a large std::vector<int> (e.g., size 10,000,000)
// Implements copy and move constructors, logging when each is called
// In main, copies and moves a LargeArray object, measuring (with std::chrono) and printing the elapsed time for each operation
// Observes that move is significantly faster than copy
#include<iostream>
#include<vector>
#include<chrono>
class LargeArray{
    std::vector<int>vec;
    public:
    LargeArray(int x):vec(10000000){
        for(int i =0;i<10000000;i++){
            vec[i]=x;
        }
    }
    LargeArray(const LargeArray& la):vec(10000000){
        std::cout<<"copy constructor"<<std::endl;
        for(int i =0;i<10000000;i++){
           vec[i]= la.vec[i];
        }
    }
    LargeArray(LargeArray&& la) noexcept 
        : vec(std::move(la.vec)) {
        std::cout << "Move constructor\n";
    }
};
int main(){
    auto start = std::chrono::high_resolution_clock::now();
    LargeArray temp(5);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Constructor time: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<std::endl;
    start = std::chrono::high_resolution_clock::now();
    LargeArray copy(temp);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()std::endl;

    start = std::chrono::high_resolution_clock::now();
    LargeArray la1(std::move(temp));
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()std::endl;


}