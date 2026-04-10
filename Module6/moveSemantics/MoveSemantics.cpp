#include<iostream>
class A{
    int* ptr;
    int size;
    public:
    A(int* ptr, int size):ptr(ptr),size(size){
        std::cout<<"the constructor gets called"<<std::endl;
    }
    A(const A& other){
        //delete(ptr);
        size = other.size;
        ptr = new int[size];
        
        for(int i =0;i<size;i++){
            ptr[i]= other.ptr[i]
        }
    }
    A& operator=( A& other){
        //other is a refernce/ alias so to get the pointer you need to access the addresss.
        if(this!=&other){
            delete(ptr);
            size = other.size;
            ptr = new int[size];
            
            for(int i =0;i<size;i++){
                ptr[i]= other.ptr[i]
            }
            
        }
        return *this;
    }
    A(A&& other){
        size = other.size;
        ptr = other.ptr;
    
        other.ptr=nullptr;
        other.size=0;
    }
    A& operator=( A&& other)noexcept{
        //other is a refernce/ alias so to get the pointer you need to access the addresss.
        if(this!=&other){
            delete(ptr);
            size = other.size;
            ptr = other.ptr;
            
            other.ptr=nullptr;
            other.size=0;
            
        }
        return *this;
    }

    ~A(){
        delete []ptr;
        std::cout<<"the destructor gets called"<<std::endl;
    }
};
int main(){


}''