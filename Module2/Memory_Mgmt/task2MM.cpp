//Allocates an array of 5 integers using new[] (int* arr1 = new int[5]) Allocates an array of 5 integers using
//malloc (int* arr2 = (int*)malloc(5 * sizeof(int))) Initializes both arrays with values
//(simple loop for assignment) Prints the contents of both arrays with clear labels Deletes
//the array allocated with new[] using delete[] (delete[] arr1) Frees the array allocated with
//malloc using free (free(arr2)) Notes type-safety and constructor/destructor behavior in
//comments/output

#include<iostream>
using namespace std;
int main() {
    int* arr = new int[5];
    int* arr2 = (int*)malloc(5*sizeof(int));
    for (int i =0;i<5;i++) {
        arr[i]=i;
        arr2[i] = 10*i;
    }

    for (int i =0;i<5;i++) {
        cout<<"The "<<i<<" th element of arr is"<< arr[i]<<endl;
        cout<<"The "<<i<<" th element of arr2 is"<< arr2[i]<<endl;
    }
    delete[] arr;
    free(arr2);

}