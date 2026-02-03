//Write a C program that:
//Prompts the user to enter :
//Employee ID(int empId)
//Current timestamp(string, manually typed by user, e.g., "2025-09-20 09:30 AM").
//Appends the attendance data(empId, timestamp) to a text file(attendance.txt) using fopen() in append mode("a") and fprintf().
//Reads and displays the full attendance log from the file using fopen() in read mode("r") and fgets().

#include <stdio.h>
int main() {
    FILE* f;
    int id;
    char time[50];

    printf("Enter Employee ID: ");
    scanf("%d", &id);
    printf("Enter Timestamp (e.g., 2025-09-20 09:30 AM): ");
    scanf(" %[^\n]", time);

    f = fopen("attendance.txt", "a");
    fprintf(f, "%d | %s\n", id, time);
    fclose(f);

    printf("Saveinggg\n\n");

    // Read and display all records 
    f = fopen("attendance.txt", "r");

    if (f == NULL) {
        printf("No records yet.\n");
        return 0;
    }

    char buffer[100];
    while (fgets(buffer, 100, f) != NULL) {
        printf("%s", buffer);
    }
    //displaying all the records.

    fclose(f);
    return 0;
}