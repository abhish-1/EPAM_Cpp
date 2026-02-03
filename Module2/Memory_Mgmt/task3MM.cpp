//Defines a function that allocates memory dynamically using new (int* allocate()) Returns the
//dynamically allocated pointer from the function to the caller In main(), calls the allocation
//function, then deletes the pointer using delete Attempts to access the pointer after delete
//to demonstrate the concept of a dangling pointer (do not expect reliable output) As an extension,
//sets the pointer to nullptr after deleting and shows safe handling (pointer reset).

#include<iostream>
int* allocate() {
    int* ptr;
    ptr = new int{};
    return ptr;
}
int main() {
    int* testingPointer = allocate();
    std::cout<<*testingPointer<<std::endl;
    delete(testingPointer);
    std::cout<<*testingPointer<<std::endl;
    std::cout<<"should be garbage"<<std::endl;
    testingPointer=nullptr;

    std::cout<<"pointer is set to null now"<<std::endl;



}