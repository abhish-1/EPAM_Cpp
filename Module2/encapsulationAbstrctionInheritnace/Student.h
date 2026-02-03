#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    int rollNo;
    int marks;

public:
    void setName(std::string name);
    void setRoll(int roll);
    void setMarks(int marks);

    std::string getName() const;
    int getRoll() const;
    int getMarks() const;
};

#endif



//What went wrong
//No function bodies{} here
//No using namespace std; in headers(good habit)
//Only what exists, not how
