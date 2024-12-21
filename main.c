#include<stdio.h>

struct Student_details
{
    char stuID[7];
    char stuName[30];
    float math_marks;
    float ccp_marks;
    float beee_marks;
    float total ;
};

int Students_details(struct Student_details *ptr);





void main()
{
    int choice,lastStu;
    printf("----------Welcome To CHARUSAT----------\n");
    printf("\n");
    printf("---------------------------------------\n");
    printf("Kindly Enter Number, Which is before \n   the task that do you want do.\n");
    printf("---------------------------------------\n");
    printf("\n");
    printf("1. Enter Students's  Details.\n");
    printf("2. Add Student's Details.\n");
    printf("3. Edit Student's Details.\n");
    printf("4. View All Student's Details.\n");
    printf("5. Delete Student's Details.\n");
    printf("6. Search for any Student.\n");
    printf("\n Enter 0 for Exit.\n");
    printf("---------------------------------------\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    struct Student_details stu[50];
    switch ( choice )
    {
        case 1 : lastStu = Students_details(&stu[0]);

    }

}

int Students_details(struct Student_details *ptr)
{
    int numOfStu;
    printf("Enter Number Of Student:");
    scanf("%d",&numOfStu);
    for(int i=0 ; i<numOfStu ;i++)
    {
        printf("Enter Details of Student no. %d\n",i+1);
        printf("Enter id :");
        scanf("%s",(ptr+i)->stuID);
        getchar();
        printf("Enter Name of Student:");
        scanf("%[^\n]",(ptr+i)->stuName);
        printf("Enter maths's mark:");
        scanf("%d",& (ptr+i)->math_marks);
        printf("Enter CCP's mark:");
        scanf("%d",& (ptr+i)->ccp_marks);
        printf("Enter BEEE's mark:");
        scanf("%d",& (ptr+i)->beee_marks);
    }
    printf("\nTHANK YOU!!");
    FILE *fptr;
    fptr = fopen("student_record.txt","a");
    
    return numOfStu;
}