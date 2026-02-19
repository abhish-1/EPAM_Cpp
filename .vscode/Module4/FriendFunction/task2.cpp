//efines a Student class with private members: name (std::string) and marks (int) Defines a Result class and 
//declares it as a friend inside Student Implements a display(Student) function inside the Result class that
// prints the student's marks and whether they passed (marks >= 50) or failed Illustrates the pass/fail decision 
//in output

#include <iostream>
#include <string>
using namespace std;

class Result;  
class Student {
    string name;
    int marks;

public:
    Student(string n, int m) : name(n), marks(m) {}

    friend class Result;  // Result can access private members
};

class Result {
public:
    void display(Student s) {
        cout << s.name << "'s marks: " << s.marks << " - ";
        if (s.marks >= 50)
            cout << "Pass" << endl;
        else
            cout << "Fail" << endl;
    }
};

int main() {
    Student s1("A", 78);
    Student s2("B", 30);

    Result res;
    res.display(s1);
    res.display(s2);

    return 0;
}
