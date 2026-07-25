//
//  main.c
//  StudentManagementSystem
//
//  Created by Subij Dhital on 25/07/2026.
//

#include <stdlib.h>
#include <stdio.h>



#define MAX_STUDENTS 100
struct Student
{
    int id;
    char name[30];
    int age;
    float gpa;
};


struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent(void)
{
    printf("\n===== Add Student =====\n");
    
    printf("Enter Student ID: ");
        scanf("%d", &students[studentCount].id);
    
    printf("Enter Name: ");
    scanf("%s", students[studentCount].name);
    
    printf("Enter Student Age: ");
    scanf("%d", &students[studentCount].age);
    
    printf("Enter Student GPA: ");
    scanf("%f", &students[studentCount].gpa);
    
          studentCount++;
    
          printf("\nStudent added successfully!\n");
    
    
    
}

int main(void)
{
    int choice;
    
    while (1)
    {
        
        printf("====================================\n");
        printf("   Student Management System\n");
        printf("====================================\n\n");
        
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        studentCount++;
        
        printf("\nStudent added successfully!\n");
        
        switch (choice)
        {
            case 1:
                addStudent();
                break;
                
            case 2:
                printf("\nView Students selected.\n");
                break;
                
            case 3:
                printf("\nSearch Student selected.\n");
                break;
                
            case 4:
                printf("\nDelete Student selected.\n");
                break;
                
            case 5:
                printf("\nExiting Program...\n");
                break;
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
}




