////Write a C program that
//Define Arithmetic Functions : Create separate C functions for add, subtract, and multiply.Each should take two int arguments and return an int.
//Declare a Function Pointer Variable : In main, declare a function pointer variable that can point to functions matching the signature 
//of your arithmetic functions(i.e., takes two ints and returns an int).
//Assign Functions to the Pointer : Assign the address of one of your arithmetic functions(e.g., add)
// to the function pointer variable.Remember that the function name itself(without()) acts as a pointer to the function.
//Call Function via Pointer : Use the function pointer variable to call the function it currently points to, passing in the required arguments.
//Reassign and Repeat : Reassign the function pointer to a different arithmetic function and call it again, demonstrating the dynamic selection.


#include<stdio.h>
int add(int num1, int num2) {
	return num1 + num2;
}
int subtract(int num1, int num2) {
	return num1 - num2;
}
int multiply(int num1, int num2) {
	return num1 * num2;
}
int divide(int num1, int num2) {
	return num1 / num2;
}
int main() {
	int (*ptr)(int, int);
	int result;
	ptr = &add;
	result = (*ptr)(2, 3);
	printf("%d", result);
	free(ptr);
	ptr = &subtract;
	result = (*ptr)(5, 3);
	printf("%d", result);
	free(ptr);



}