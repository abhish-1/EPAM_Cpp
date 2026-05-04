// Dynamically allocates multiple objects (e.g., int* or a simple class) in a loop using new.
// Deletes only some of the objects, intentionally leaking the rest.
// Runs under Valgrind (Linux/macOS) or with CRT leak checking (Windows) to identify and report the leaked memory blocks.

#include<iostream>
using namespace std;
class Apple{
    public:

    int* arr = new int[5];
    Apple(){
    
    }
    ~Apple(){
        delete [] arr;
    }
};
int main(){
    Apple* app = new Apple[5];

}