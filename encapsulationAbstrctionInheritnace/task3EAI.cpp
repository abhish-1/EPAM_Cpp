//Define the Student class in Student.h with private members: name (std::string), 
// rollNo (int), marks (int) Implement all class member functions in Student.cpp
// Include range-checking in setMarks(int) to only accept values between 0 and 
// 100 Use the Student class in main.cpp to confirm encapsulation and correct API usage

#include"Student.h";
void setName(std::string name) {
	Student::name->name;
}
void setRoll(int roll) {
	Student::roll->roll;
}
void setMarks(int marks) {
	if (marks < 0 || marks>100) {
		cout << "please enter valid marks";
	}
	else {
		Student::marks->marks;
	}
}

std::string getName() const {
	return name;
}
int getRoll() const {
	return roll;
}
int getMarks() const {
	return marks;
}

