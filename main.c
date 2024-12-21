#include<stdio.h>

void main()
{
    FILE *fptr ;
    fptr = fopen("student_record.txt","a");
    printf("----------Welcome To CHARUSAT----------\n");
    printf("\n");
    printf("---------------------------------------\n");
    printf("Kindly Enter Number, Which is before the task that do you want do.\n");
    printf("---------------------------------------\n");
    printf("\n");
    printf("1. Add Student's Details.\n");
    printf("2. Edit Student's Details.\n");
    printf("3. View All Student's Details.\n");
    printf("4. Delete Student's Details.\n");
    printf("5. Search for any Student.\n");
    printf("\n Enter 0 for Exit.\n");
    printf("---------------------------------------\n");


}