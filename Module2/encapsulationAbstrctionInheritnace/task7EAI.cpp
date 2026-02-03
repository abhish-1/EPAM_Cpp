//Defines a base class Person with data members: name (std::string) 
// and age (int) Derives a Student class that adds rollNo (int) and 
// grade (char) Derives a Teacher class that adds subject (std::string)
// and salary (double) Demonstrates how derived classes use base class
//members (e.g., setting and displaying name and age for Student/Teacher
// objects)

#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    //cuz inherited class can access protected,public only.
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    string getName() const { 
        return name; 
    }
    int getAge() const { 
        return age; 
    }
    void display() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Student : public Person {
    int rollNo;
    char grade;

public:
    Student(string n = "", int a = 0, int r = 0, char g = 'A')
        : Person(n, a), rollNo(r), grade(g) {
    }

    void setRollNo(int r) { rollNo = r; }
    void setGrade(char g) { grade = g; }

    int getRollNo() const { return rollNo; }
    char getGrade() const { return grade; }

    void display() const {
        Person::display();  
        cout << ", Roll No: " << rollNo << ", Grade: " << grade << endl;
    }
};

class Teacher : public Person {
    string subject;
    double salary;

public:
    Teacher(string n = "", int a = 0, string s = "", double sal = 0.0)
        : Person(n, a), subject(s), salary(sal) {
    }

    void setSubject(string s) { subject = s; }
    void setSalary(double sal) { salary = sal; }

    string getSubject() const { return subject; }
    double getSalary() const { return salary; }

    void display() const {
        Person::display();  // Call base class display
        cout << ", Subject: " << subject << ", Salary: $" << salary << endl;
    }
};

int main() {
   
    Student s2;
    s2.setName("Abhishek");
    s2.setAge(22);
    s2.setRollNo(1);
    s2.setGrade('A');

    s2.display();

    return 0;
}