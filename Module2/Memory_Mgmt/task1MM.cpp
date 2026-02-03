//Define a class Tracker that overloads operator new and operator
//delete (class Tracker) Prints a message each time memory is allocated
//or freed by Tracker’s new/delete operators (std::cout) Allocates
//multiple Tracker objects using the new operator (dynamic memory
//allocation) Deliberately omits delete for some objects to simulate
//\leaks Counts the number of active allocations; displays the count
//at program termination Reports which memory allocations were not
//freed (extension: counter implementation)
#include<iostream>
static int count=0;
class Tracker {
public:
    void* operator new(size_t size){
        std::cout<<"Full on space implementation guys"<<std::endl;
        void* ptr =malloc(size);
        count++;
        std::cout<<"Done on space implementation guys using malloc"<<std::endl;
        return ptr;
    }
    void operator delete (void* ptr){
        std::cout<<"I am gonna delete this thing";
        free(ptr);
        std::cout<<"I am gonna delete this thing";
        count--;
        //new Tracker[4];
    }
};
int main() {
    void* t1 = new Tracker();
    std::cout<<"The first pointer gets created"<<std::endl;
    std::cout<<"The count is "<<count<<std::endl;
    void* t2 = new Tracker();
    std::cout<<"The first pointer gets created"<<std::endl;
    std::cout<<"The count "<<count<<std::endl;
    void* t3 = new Tracker();
    std::cout<<"The first pointer gets created"<<std::endl;
    std::cout<<"The count is "<<count<<std::endl;
    delete(t2);
    std::cout<<"The first pointer gets deleted"<<std::endl;
    std::cout<<"The count is "<<count<<std::endl;
    return 0;

}
