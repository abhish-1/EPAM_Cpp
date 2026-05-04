// Write a C++ program that:

// Dynamically allocates an integer array using new
// Does not free the memory with delete[]
// Compiles and runs the program
// Uses CRT methods (on Windows, _CrtDumpMemoryLeaks()) to detect the leak

#include <iostream>
using namespace std;
int main() {
    int* ptr = new int[10]; 
    ptr[0] = 42; 
    delete [] ptr;
    return 0;
}