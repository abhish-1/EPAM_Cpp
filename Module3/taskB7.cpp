//Defines an abstract base class Person with a pure virtual displayInfo()
//Derives Student and Employee from Person using virtual inheritance
//Derives TeachingAssistant from both Student and Employee
//Implements displayInfo() in TeachingAssistant
//Demonstrates that TeachingAssistant has only one Person subobject(e.g., prints address)

#include <iostream>
using namespace std;
class Person {
public:
    virtual void displayInfo() const = 0;
    virtual ~Person() {}
};
class Student : virtual public Person {
public:
    Student() {
        cout << "Student constructor\n";
    }
};
class Employee : virtual public Person {
public:
    Employee() {
        cout << "Employee constructor\n";
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant() {
        cout << "TeachingAssistant constructor called\n";
    }

    void displayInfo() const override {
        cout << "I m a Teaching Assistant\n";
    }
};

int main() {
    TeachingAssistant ta;
    ta.displayInfo();
    Person* p1 = static_cast<Student*>(&ta);
    Person* p2 = dynamic_cast<Employee*>(&ta);
    cout << "Person via Student:  " << p1 << endl;
    cout << "Person via Employee: " << p2 << endl;

    return 0;
}

//Student constructor
//Employee constructor
//TeachingAssistant constructor called
//I m a Teaching Assistant
//Person via Student : 0x7ffce070b070
//Person via Employee : 0x7ffce070b070