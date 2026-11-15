#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char programme[20];
    float grade;
} Student;

void fillStudents(Student *students, int length, char *argv[]);

int main(int argc, char *argv[])
{
    Student *students = malloc(2 * sizeof(Student));

    if (students == NULL) {
        return 1;
    }

    int number = (argc - 1) / 3;

    if (number > 2) {
        students = realloc(students, number * sizeof(Student));
        if (students == NULL) {
            return 1;
        }
    }

    fillStudents(students, number, argv);

    for (int i = 0; i < number; i++) {
        printf("%s, %s, %.2f\n", students[i].name, students[i].programme, students[i].grade);
    }

    free(students);
    students = NULL;
    return 0;
}

void fillStudents(Student *students, int length, char *argv[])
{
    int index = 1;

    for (int i = 0; i < length; i++) {
        strcpy(students[i].name, argv[index]);
        strcpy(students[i].programme, argv[index + 1]);
        students[i].grade = atof(argv[index + 2]);
        index += 3;
    }
}