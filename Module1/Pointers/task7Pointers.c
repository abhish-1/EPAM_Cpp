//Write a C program that should has Arithmetic Operation Functions:
//Create four standard C functions : add, subtract, multiply, and divide.
//Each of these functions should take two int arguments(the operands) and return an int(the result of the operation).
//Special Consideration for divide : Implement basic error handling within the divide function to prevent division by zero.
// If the divisor is zero, it should return a predefined error value(e.g., 0 or a specific INT_MIN from <limits.h>, or print an error and exit).
#include<iostream>
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
	if (num2 == 0) {
		cout << "Sorry can't divide by zero." << endl;
		return -1;
	}
	return num1 / num2;
}
int main() {
	int result = add(2, 3);
	printf("%d", result);
	int result = subtract(2, 3);
	printf("%d", result);
	int result = multiply(2, 3);
	printf("%d", result);
}