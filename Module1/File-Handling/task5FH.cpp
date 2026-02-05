#include <iostream>
#include <fstream>
#include <cstdio>   // for remove, rename make note of
using namespace std;

struct Employee {
    int empId;
    char name[50];
    float salary;
};

int main() {
    ifstream originalFile("employee.dat", ios::binary);
    if (!originalFile) {
        cout << "No file opened\n";
        return 1;
    }

    ofstream newFile("temp.dat", ios::binary);
    if (!newFile) {
        cout << "No file opened\n";
        originalFile.close();
        return 1;
    }

    int target;
    cout << "Please enter emp id: ";
    cin >> target;

    Employee emp;
    bool found = false;

    while (originalFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        if (emp.empId == target) {
            cout << "Deleting employee\n";
            found = true;
        }
        else {
            newFile.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        }
    }

    originalFile.close();
    newFile.close();

    if (found) {
        remove("employee.dat");
        rename("temp.dat", "employee.dat");
        cout << "Employee deleted successfully!\n";
    }
    else {
        cout << "Employee ID " << target << " not found!\n";
        remove("temp.dat");
    }

    return 0;
}
