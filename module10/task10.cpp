// uninit_ptr_crash.cpp
#include <iostream>
using namespace std;
int main() {
    int* ptr;     // UNINITIALIZED pointer
    cout<<ptr<<endl;
    *ptr = 10;    // Dereference triggers undefined behavior/crash
    std::cout << *ptr << std::endl;
    return 0;
}
