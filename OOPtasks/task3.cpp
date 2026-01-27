//Implements a Student class with data members : rollNo(int), name(string), grade(char) Provides a default 
//constructor which sets default values and prints a message. Provides a parameterized constructor using 
// an initialization list to set all member values; also prints a message Demonstrates object creation 
// using both constructors
#include<iostream>
#include<string>
using namespace std;
class Student {
	int rollNo;
	std::string name;
	char grade;
	public :
		Student(int rollNo, std::string name, char grade) : grade(grade), rollNo(rollNo), name(name) {

		cout << "the name of this kid is " << name 
			<< " he scored a grade of" << grade 
			<< " and has roll of " << rollNo << endl;
		}

		Student() {
			rollNo = 0;
			grade = '-';
			name = "";
			std::cout << "default constructor in case you initialise without parameters" << endl;
		}



};

int main() {
	Student s1(19, "abhishek", 'A');
	return 0;
}
