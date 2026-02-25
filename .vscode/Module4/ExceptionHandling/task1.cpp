// //Task:
// Write a C++ program with following instructions
// Define a division function: Create a C++ function and name it divide(int numerator, int denominator),
// that is intended to perform integer division.
// Implement the error check: Inside your divide function, before performing the actual division, add an
// if statement to check if the denominator parameter is 0.
// Throw an exception: If the denominator is 0, use the throw keyword to signal an error.
// For this task, you can throw a simple string literal (e.g., "Error: Division by zero!") OR
// An object of a standard exception type, such as std::runtime_error (e.g., throw std::runtime_error("Division 
//by zero cannot be performed.");). Remember to include if using std::runtime_error.
// Perform division: If the denominator is not 0, perform the integer division and return the result.
// In main, get user input: In your main function, prompt the user to enter two integers: one for the 
//numerator and one for the denominator.
// Use try-catch: Wrap the call to your divide function within a try block.
// Catch the exception: Immediately following the try block, add a catch block that is designed to 
//specifically handle the type of exception you throw from your divide function.
// If you threw a string literal, your catch block signature would be catch (const char* msg).
// If you threw std::runtime_error, your catch block signature would be catch (const std::runtime_error& e).
// Handle the error: Inside the catch block, print an informative error message to the console. If 
//you caught an std::runtime_error object, you can access its message using e.what().
// Display result: If no exception is thrown (i.e., the try block completes successfully), print the
// calculated result of the division.

#include<iostream>
#include<stdexcept>
using namespace std;
float division(int numerator, int denominator){
    if(denominator==0){
        throw std::runtime_error("Division by zero cant be performed");
    }
    else{
        return (float)numerator/denominator;
    }
}
int main(){
    float numerator, denominator;
    cout<<"Enter 2 numbers to perform division ";
    cin>>numerator>>denominator;
    try{
        float a = division(numerator, denominator);
        cout<<a;
    }
    catch(const std::runtime_error& e){
        cout<<"encountered an error "<< e.what();
    }
    return 0;
}