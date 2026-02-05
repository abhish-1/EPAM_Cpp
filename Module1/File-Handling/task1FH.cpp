//Defines a struct Student with the following fields :
//int rollNo; → Stores the student’s roll number.
//char name[50]; → Stores the student’s name(maximum 50 characters).
//float marks; → Stores the student’s marks.
//Implements the following menu :
//1. Add Student Record → Prompts the user for input and appends the record to a binary file(students.dat) using fopen() with mode "ab" and fwrite().
//2. Display All Records → Reads from the binary file(students.dat) using fopen() with mode "rb" and fread(), and prints all records in a formatted manner.
//Ensures proper error handling(e.g., file not found, empty file).

#include <stdio.h>
struct Student {
    int rollNo;
    char name[50];
    float marks;
};
int main() {
    int choice;
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("Enter choice: ");
    scanf("%d", &choice); //C: You must give address explicitly with &
    //C++: >> operator takes care of it using references, under the hood the same thing happens.
    //C++ hides the complexity so you don't need & for simple input.
    //int a; scanf("%d", &a);     
    //float b; scanf("%f", &b);   
    //char c; scanf(" %c", &c);  
    //char s[50]; scanf("%s", s); 

    if (choice == 1) {
        // ADDING STUDEnt (Writing)

        struct Student s; 
        printf("Enter Roll No: ");
        scanf("%d", &s.rollNo);
        printf("Enter Name: ");
        scanf(" %[^\n]", s.name);  
        printf("Enter Marks: ");
        scanf("%f", &s.marks);

        // Open the notebook in "Append Binary" mode
        // "ab" = Add to end + Binary mode
        FILE* file = fopen("students.dat", "ab");

        if (file == NULL) {
            printf("Error: Could not open file!\n");
            return ;
        }

        fwrite(&s, sizeof(struct Student), 1, file);
        //fwrite(what to paste, size of one, count, file pointer);
        printf("Student added successfully!\n");
        fclose(file); 
        // unless you do close() the data stays actually in buffer so if u didnt close, you gonna lose the data.
    }
    else if (choice == 2) {

        // Open notebook in "Read Binary" mode
        //Binary mode copies EXACT memory bytes (0s/1s), text mode converts data for human reading (adds/removes formatting characters).
        FILE* file = fopen("students.dat", "rb");

        if (file == NULL) {
            printf("No records found!\n");
            return 1;
        }

        struct Student s;  // Temporary form to hold each student

        // Read one form at a time until end of file (1 or 0)).
        while (fread(&s, sizeof(struct Student), 1, file) == 1) {
            printf("Roll No: %d\n", s.rollNo);
            printf("Name: %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
        }

        fclose(file);
    }

    return 0;
}