//
//  main.c
//  StudentManagementSystem
//
//  Created by Subij Dhital on 25/07/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "student.h"



#define MAX_STUDENTS 100



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






