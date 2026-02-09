#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    int id;
public:
    Employee(string name, int id) : name(name), id(id) {}

    string getName() const { return name; }
    int getId() const { return id; }

    void setName(string newName) { name = newName; }
    void setId(int newId) { id = newId; }

    virtual int calculatePay() = 0;
    virtual ~Employee() {} 
};
class SalariedEmployee : public Employee {
    int salary;
public:
    SalariedEmployee(string name, int id, int salary) :Employee(name, id), salary(salary) {}
    int calculatePay() override {
        return salary / 30;
    }
};
class HourlyEmployee : public Employee {
    int hoursWorked = 0;
    int hourlyRate = 0;
public:
    HourlyEmployee(string name, int id, int hoursWorked, int hourlyRate) :Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    int calculatePay() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    vector<Employee*> employees;
    employees.push_back(new SalariedEmployee("aman", 23, 10000));
    employees.push_back(new HourlyEmployee("naman", 54, 150, 25));

    for (auto emp : employees) {
        cout << emp->getName() << endl;
        cout << emp->calculatePay() << endl;
    }

    for (auto emp : employees) delete emp;

    return 0;
}