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
   
void viewstudent(void)
{
    int i;

        printf("\n========== STUDENT LIST ==========\n");

        if (studentCount == 0)
        {
            printf("No students found.\n");
            return;
        }

        for (i = 0; i < studentCount; i++)
        {
            printf("\nStudent %d\n", i + 1);
            printf("ID   : %d\n", students[i].id);
            printf("Name : %s\n", students[i].name);
            printf("Age  : %d\n", students[i].age);
            printf("GPA  : %.2f\n", students[i].gpa);
        }
}
    
void searchStudent(void)
{
    int id;
       int i;

       printf("\nEnter Student ID to search: ");
       scanf("%d", &id);
    
    for(i = 0; i < studentCount; i++)
    {
        if(students[i].id == id)
        {
            printf("\nStudent Found!\n");
            printf("ID   : %d\n", students[i].id);
            printf("Name : %s\n", students[i].name);
            printf("Age  : %d\n", students[i].age);
            printf("GPA  : %.2f\n", students[i].gpa);

            return;
        }
       
    }
    printf("\nStudent not found.\n");
}

void deleteStudent(void)
{
    int id;
    int i;
    int found = 0;
    
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    
    for(i = 0; i < studentCount; i++)
    {
        if(students[i].id == id)
        {
            for(int j = i; j < studentCount - 1; j++)
            {
                students[j] = students[j + 1];
            }
            studentCount--;
            found = 1;

            printf("\nStudent deleted successfully!\n");

            break;
        }
    }
    if(found == 0)
    {
        printf("\nStudent not found.\n");
    }

}

void saveStudents(void)

{
    int i;
    FILE *fp;

      fp = fopen("students.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
        
       
        for(i = 0; i < studentCount; i++)
        {
            fprintf(fp, "%d %s %d %.2f\n",
                    students[i].id,
                    students[i].name,
                    students[i].age,
                    students[i].gpa);
        }
    
    fclose(fp);

    printf("Students saved successfully!\n");
}

void loadStudents(void)
{
    FILE *fp;

    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("No saved data found.\n");
        return;
    }

    studentCount = 0;

    while (fscanf(fp, "%d %s %d %f",
                  &students[studentCount].id,
                  students[studentCount].name,
                  &students[studentCount].age,
                  &students[studentCount].gpa) == 4)
    {
        studentCount++;
    }

    fclose(fp);

    printf("\n%d students loaded successfully!\n", studentCount);
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
        printf("5. Save Students\n");
        printf("6. Load Students\n");
        printf("7. Exit\n\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        
        
        switch (choice)
        {
            case 1:
                addStudent();
                break;
                
            case 2:
                viewstudent();
                break;
                
            case 3:
                searchStudent();
                    break;
                
            case 4:
                deleteStudent();
                break;
                
            case 5:
                    saveStudents();
                    break;

                case 6:
                    loadStudents();
                    break;

                case 7:
                    printf("\nExiting Program...\n");
                    return 0;

                default:
                    printf("\nInvalid choice!\n");
            }
    }
}






