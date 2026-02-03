//Write a C program that :
//Reads employee records from the binary file(employee.dat) :
//	Employee Struct :
//int empId; → Employee ID.
//char name[50]; → Employee name.
//float basicSalary; → Basic salary.
//Calculates the net salary for each employee :
//DA = basicSalary * 0.2
//HRA = basicSalary * 0.1
//netSalary = basicSalary + DA + HRA
//Writes formatted salary slips into separate files named based on the employee ID, e.g., emp101_slip.txt.

// sprintf? -> how does it work?

#include <stdio.h>
struct Employee {
    int empId;
    char name[50];
    float basicSalary;
};

int main() {
    FILE* inputFile;
    FILE* outputFile;
    struct Employee emp;
    char filename[50];

    // Open employee data file
    inputFile = fopen("employee.dat", "rb"); //read bniary
    if (inputFile == NULL) {
        printf("Error Cannot open employee.dat\n");
        return 0;
    }

    // Reading employee
    while (fread(&emp, sizeof(struct Employee), 1, inputFile) == 1) {
        // Calculate salary components
        float DA = emp.basicSalary * 0.2;
        float HRA = emp.basicSalary * 0.1;
        float netSalary = emp.basicSalary + DA + HRA;

        // Create output filename (emp101_slip.txt)
        sprintf(filename, "emp%d_slip.txt", emp.empId);
        //can say it as a way to concatantion used for file naming in our case.

        // Open slip file for writing
        outputFile = fopen(filename, "w");
        if (outputFile == NULL) {
            printf("Error creating slip for employee %d\n", emp.empId);
            continue;
        }

        // Write salary slip
        fprintf(outputFile, "Employee ID: %d\n", emp.empId);
        fprintf(outputFile, "Name: %s\n", emp.name);
        fprintf(outputFile, "Basic Salary: %.2f\n", emp.basicSalary);
        fprintf(outputFile, "DA (20%%): %.2f\n", DA);
        fprintf(outputFile, "HRA (10%%): %.2f\n", HRA);
        fprintf(outputFile, "Net Salary: %.2f\n", netSalary);

        printf("Created slip: %s\n", filename);
        fclose(outputFile);
    }

    fclose(inputFile);
    return 0;
}