// asan_example.cpp
#include <iostream>
int main() {
    int* arr = new int[5];
    arr[6] = 123;             
    delete[] arr;
    return 0;
}
