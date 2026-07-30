#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

struct Student
{
    int id;
    char name[30];
    int age;
    float gpa;
};

extern struct Student students[MAX_STUDENTS];
extern int studentCount;

void addStudent(void);
void viewstudent(void);
void searchStudent(void);
void deleteStudent(void);
void saveStudents(void);
void loadStudents(void);

#endif
