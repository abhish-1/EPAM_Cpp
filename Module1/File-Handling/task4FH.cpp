//Opens the binary file (students.dat) in read/write binary mode ("r+b").
//Searches for a Student record using the roll number(rollNo).
//If the record is found, computes its position in the file using fseek() and updates the marks field directly.
//Writes the modified record back to the same position using fwrite().
#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    FILE* file = fopen("students.dat", "rb+"); //read and write
    if (!file) {
        printf("File not found!\n");
        return 1;
    }

    struct Student s;
    int rollToUpdate;
    float newMarks;

    printf("Enter Roll No to update: ");
    scanf("%d", &rollToUpdate);
    printf("Enter new marks: ");
    scanf("%f", &newMarks);

    // Search for student
    while (fread(&s, sizeof(s), 1, file) == 1) {
        if (s.rollNo == rollToUpdate) {
            //the pointer moves one step just after it reads so get back one step.
            // Move back one record
            fseek(file, -sizeof(s), SEEK_CUR);
            //Better way (seek_curl for knowning the current position, get back by size of (s).

            // Update, write
            s.marks = newMarks;
            fwrite(&s, sizeof(s), 1, file);

            printf("Updated Roll %d now marks %.2f\n", s.rollNo, s.marks);
            fclose(file);
            return 0;
        }
    }

    printf("Student not found!\n");
    fclose(file);
    return 0;
}