#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.txt";

typedef struct
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char course[50];
} Student;

void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear invalid input
            continue;
        }

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addStudent()
{
    FILE *file = fopen(FILENAME, "ab"); // Open in binary append mode if (file == NULL) { perror("Unable to open file"); return; }

    Student student;

    printf("Enter Student ID: ");
    while (scanf("%d", &student.id) != 1)
    {
        printf("Invalid ID! Please enter a valid integer: ");
        while (getchar() != '\n')
            ; // Clear invalid input
    }

    while (getchar() != '\n')
        ; // Clear the newline after ID input

    printf("Enter Name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Age: ");
    while (scanf("%d", &student.age) != 1 || student.age <= 0)
    {
        printf("Invalid age! Please enter a valid positive integer: ");
        while (getchar() != '\n')
            ;
    }

    while (getchar() != '\n')
        ;

    printf("Enter Gender: ");
    fgets(student.gender, sizeof(student.gender), stdin);
    student.gender[strcspn(student.gender, "\n")] = '\0';

    printf("Enter Course: ");
    fgets(student.course, sizeof(student.course), stdin);
    student.course[strcspn(student.course, "\n")] = '\0';

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully.\n");
}

void viewStudents()
{
    FILE *file = fopen(FILENAME, "rb"); // Open in binary read mode if (file == NULL) { perror("Unable to open file"); return; }

    Student student;

    printf("\nID\tName\t\tAge\tGender\t\tCourse\n");
    printf("-------------------------------------------------------------\n");

    while (fread(&student, sizeof(Student), 1, file))
    {
        printf("%d\t%-15s\t%d\t%-10s\t%s\n", student.id, student.name, student.age, student.gender, student.course);
    }

    fclose(file);
}

void updateStudent()
{
    int id;
    printf("Enter Student ID to update: ");
    while (scanf("%d", &id) != 1)
    {
        printf("Invalid ID! Please enter a valid integer: ");
        while (getchar() != '\n')
            ; // Clear invalid input }

        FILE *file = fopen(FILENAME, "r+b"); // Open in read-write binary mode
        if (file == NULL)
        {
            perror("Unable to open file");
            return;
        }

        Student student;
        int found = 0;

        while (fread(&student, sizeof(Student), 1, file))
        {
            if (student.id == id)
            {
                found = 1;

                printf("Enter new Name: ");
                while (getchar() != '\n')
                    ; // Clear buffer
                fgets(student.name, sizeof(student.name), stdin);
                student.name[strcspn(student.name, "\n")] = '\0'; // Remove trailing newline

                printf("Enter new Age: ");
                while (scanf("%d", &student.age) != 1 || student.age <= 0)
                {
                    printf("Invalid age! Please enter a valid positive integer: ");
                    while (getchar() != '\n')
                        ; // Clear invalid input
                }

                printf("Enter new Gender: ");
                while (getchar() != '\n')
                    ; // Clear buffer
                fgets(student.gender, sizeof(student.gender), stdin);
                student.gender[strcspn(student.gender, "\n")] = '\0';

                printf("Enter new Course: ");
                fgets(student.course, sizeof(student.course), stdin);
                student.course[strcspn(student.course, "\n")] = '\0';

                fseek(file, -sizeof(Student), SEEK_CUR); // Move back one record
                fwrite(&student, sizeof(Student), 1, file);
                printf("Student record updated successfully.\n");
                break;
            }
        }

        if (!found)
        {
            printf("Student ID not found.\n");
        }

        fclose(file);
    }

    void deleteStudent()
    {
        int id;
        printf("Enter Student ID to delete: ");
        while (scanf("%d", &id) != 1)
        {
            printf("Invalid ID! Please enter a valid integer: ");
            while (getchar() != '\n')
                ; // Clear invalid input }

            FILE *file = fopen(FILENAME, "rb"); // Open in binary read mode
            if (file == NULL)
            {
                perror("Unable to open file");
                return;
            }

            FILE *tempFile = fopen("temp.txt", "wb"); // Open a temporary file in binary write mode
            if (tempFile == NULL)
            {
                perror("Unable to open temporary file");
                fclose(file);
                return;
            }

            Student student;
            int found = 0;

            while (fread(&student, sizeof(Student), 1, file))
            {
                if (student.id != id)
                {
                    fwrite(&student, sizeof(Student), 1, tempFile);
                }
                else
                {
                    found = 1;
                }
            }

            fclose(file);
            fclose(tempFile);

            remove(FILENAME);
            rename("temp.txt", FILENAME);

            if (found)
            {
                printf("Student record deleted successfully.\n");
            }
            else
            {
                printf("Student ID not found.\n");
            }
        }