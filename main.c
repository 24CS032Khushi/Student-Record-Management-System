//Project made by KHUSHI KAPATEL
//Students Management System Using C Language.
#include<stdio.h>
#include<string.h>

struct Student_details
{
    char stuID[8];
    char stuName[30];
    float math_marks;
    float ccp_marks;
    float beee_marks;
    float total ;
};

int Students_details(struct Student_details *ptr);
int Add_Student_details(struct Student_details *ptr , int index);
void Sorting_StuDetails(struct Student_details *ptr , int total_stu);
void PrintingDetails_inFile(struct Student_details *ptr , int total_stu);
void Edit_stuDetails(struct Student_details *ptr , int total_stu);
void ViewAll_StuDetails(struct Student_details *ptr, int total_stu);
int Delete_detailOfstu(struct Student_details *ptr , int index);
void Search_stuDetails(struct Student_details *ptr,int total_stu);
void PrintingFinalDetails_inFile(struct Student_details *ptr ,int total_stu);


void main()
{
    int choice,lastStu=0;
    printf("\n");
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
    printf("7. For Printing Final Details.\n");
    printf("\n Enter 0 for Exit.\n");
    printf("---------------------------------------\n");
    restart:
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    struct Student_details stu[50];
    switch ( choice )
    {
        case 1 : lastStu = Students_details(&stu[0]);
                 goto restart;
        case 2 : lastStu = Add_Student_details(&stu[0],lastStu);
                 goto restart;
        case 3 : Edit_stuDetails(&stu[0],lastStu);
                 goto restart;
        case 4 : ViewAll_StuDetails(&stu[0],lastStu);
                 goto restart;
        case 5 : lastStu = Delete_detailOfstu(&stu[0],lastStu);
                 goto restart;
        case 6 : Search_stuDetails(&stu[0],lastStu);
                 goto restart;
        case 7 : PrintingFinalDetails_inFile(&stu[0],lastStu);
        case 0 : printf("----------------------------------------\n");
                 printf("THANK YOU!!\n");
                 printf("----------------------------------------\n");
                 break ;
                

    }

}

void Sorting_StuDetails(struct Student_details *ptr , int total_stu)
{
    struct Student_details temp; 

        for(int i=0 ; i<total_stu ; i++)
        {
            for(int j = i+1 ; j<total_stu ; j++)
            {
                if( strcmp( (ptr+i)->stuID , (ptr+j)->stuID ) > 0 )
                {
                    temp = ptr[j];
                    ptr[j] = ptr[i];
                    ptr[i] = temp;
                }
            }
        }
}

void PrintingDetails_inFile(struct Student_details *ptr , int total_stu)
{
    FILE *fptr;
    fptr = fopen("student_record.txt","w");
    for(int i=0 ; i<total_stu ; i++)
    {
        fputs((ptr+i)->stuID , fptr );
        fprintf(fptr ,"\t\t\t");
        fprintf(fptr , "%s" , (ptr+i)->stuName);
        fprintf(fptr ,"\t\t");
        fprintf(fptr,"%f\t\t",(ptr+i)->math_marks);
        fprintf(fptr,"%f\t\t",(ptr+i)->ccp_marks);
        fprintf(fptr,"%f\t\t",(ptr+i)->beee_marks);
        fprintf(fptr,"%f\n",(ptr+i)->total);
    }
    fclose(fptr);
}



int Students_details(struct Student_details *ptr)
{
    int numOfStu;
    printf("----------------------------------------\n");
    printf("Now You can add Details of Students.\n\n");
    printf("Enter Number Of Student:");
    scanf("%d",&numOfStu);
    getchar();

    for(int i=0 ; i<numOfStu ;i++)
    {
        printf("----------------------------------------\n");
        printf("Enter Details of Student no. %d\n\n",i+1);
        
        printf("Enter Name of Student:");
        fgets((ptr+i)->stuName,sizeof((ptr+i)->stuName),stdin);
        
        size_t len = strlen((ptr + i)->stuName);
        if ((ptr + i)->stuName[len - 1] == '\n')
        {
            (ptr + i)->stuName[len - 1] = '\0';
        }
            
        printf("Enter id :");
        fgets((ptr+i)->stuID,sizeof((ptr+i)->stuID),stdin);
        len = strlen((ptr + i)->stuID);
        if ((ptr + i)->stuID[len - 1] == '\n')
        {
            (ptr + i)->stuID[len - 1] = '\0';
        }
        
        getchar();
     
        printf("Enter Maths's mark:");
        scanf("%f",&(ptr+i)->math_marks);

        printf("Enter CCP's mark:");
        scanf("%f",&(ptr+i)->ccp_marks);

        printf("Enter BEEE's mark:");
        scanf("%f",&(ptr+i)->beee_marks);

        (ptr+i)->total = (ptr+i)->math_marks + (ptr+i)->ccp_marks + (ptr+i)->beee_marks ;
        getchar();

        }

        Sorting_StuDetails(ptr,numOfStu);
        PrintingDetails_inFile(ptr,numOfStu);
        
        printf("\nTHANK YOU!!\n");
        printf("--------------------------------------\n");

    return numOfStu;
}

int Add_Student_details(struct Student_details *ptr , int index)
{
    getchar();
    if(index==0)
    {
        printf("----------------------------------------\n");
        printf("There is no existing list of Student Details>\n");
        printf("\nTHANK YOU!!\n");
        printf("--------------------------------------\n");
        return 0;
   
    }
    printf("----------------------------------------\n\n");
    printf("Now You can add Details of Students in existing list.\n\n");
    printf("----------------------------------------\n");
    printf("Enter Name of Student:");
    fgets((ptr+index)->stuName,sizeof((ptr+index)->stuName),stdin);
    size_t len = strlen((ptr + index)->stuName);
    if ((ptr + index)->stuName[len - 1] == '\n')
    {
        (ptr + index)->stuName[len - 1] = '\0';
    }

    printf("Enter id :");
    fgets((ptr+index)->stuID,sizeof((ptr+index)->stuID),stdin);
    len = strlen((ptr + index)->stuID);
    if ((ptr + index)->stuID[len - 1] == '\n')
    {
        (ptr + index)->stuID[len - 1] = '\0';
    }
        
    getchar();
     
    printf("Enter Maths's mark:");
    scanf("%f",&(ptr+index)->math_marks);

    printf("Enter CCP's mark:");
    scanf("%f",&(ptr+index)->ccp_marks);

    printf("Enter BEEE's mark:");
    scanf("%f",&(ptr+index)->beee_marks);

    (ptr+index)->total = (ptr+index)->math_marks + (ptr+index)->ccp_marks + (ptr+index)->beee_marks ;
    getchar();

    index = index+1;

    Sorting_StuDetails(ptr,index);
    PrintingDetails_inFile(ptr,index);

    
    printf("\nTHANK YOU!!\n");
    printf("--------------------------------------\n");
    return index;

}

void Edit_stuDetails(struct Student_details *ptr , int total_stu)
{
    getchar();
    if(total_stu==0)
    {
        printf("----------------------------------------\n");
        printf("There is no existing list of Student Details.\n");
        printf("\nTHANK YOU!!\n");
        printf("--------------------------------------\n");
   
    }
    else
    {
        int flag=1;
        printf("----------------------------------------\n");
        printf("Now You Can Edit any Student's Detail via\n");
        printf("              Student ID\n");
        char id[8];
        printf("Enter Student ID:");
        scanf("%s",id);
        
        getchar();
        for(int i=0 ; i<total_stu ; i++)
        {
            if(strcmp(id,(ptr+i)->stuID)==0)
            {
                printf("Edit Details:\n");
                printf("--------------------------------------\n");
                printf("Enter Name of Student:");
                fgets((ptr+i)->stuName,sizeof((ptr+i)->stuName),stdin);
                size_t len = strlen((ptr + i)->stuName);
                if ((ptr + i)->stuName[len - 1] == '\n')
                {
                    (ptr + i)->stuName[len - 1] = '\0';
                }

                printf("Enter id :");
                fgets((ptr+i)->stuID,sizeof((ptr+i)->stuID),stdin);
                len = strlen((ptr + i)->stuID);
                if ((ptr + i)->stuID[len - 1] == '\n')
                {
                    (ptr + i)->stuID[len - 1] = '\0';
                }
                    
                getchar();
                
                printf("Enter maths's mark:");
                scanf("%f",&(ptr+i)->math_marks);

                printf("Enter CCP's mark:");
                scanf("%f",&(ptr+i)->ccp_marks);

                printf("Enter BEEE's mark:");
                scanf("%f",&(ptr+i)->beee_marks);

                (ptr+i)->total = (ptr+i)->math_marks + (ptr+i)->ccp_marks + (ptr+i)->beee_marks ;
                getchar();

                Sorting_StuDetails(ptr,total_stu);
                PrintingDetails_inFile(ptr,total_stu);
                printf("Edit is Successfuly Done.!!\n");
                flag=0;
            }
            
        }
        if(flag)
        {
            printf("There is no such ID.\n");
        }
        printf("THANK YOU!!\n");
        printf("--------------------------------------\n");
     
    }

}

void ViewAll_StuDetails(struct Student_details *ptr, int total_stu)
{
    printf("--------------------------------------\n\n");
    for(int i=0 ; i<total_stu ; i++)
    {
        printf("Name : ");
        puts((ptr+i)->stuName);
        printf("\n");
        printf("ID: ");
        puts((ptr+i)->stuID);
        printf("\n");
        printf("Marks of Maths: %f\n",(ptr+i)->math_marks);
        printf("Marks of CCP  : %f\n",(ptr+i)->ccp_marks);
        printf("Marks of BEEE : %f\n",(ptr+i)->beee_marks);
        printf("Total Marks   : %f\n",(ptr+i)->total);
        printf("--------------------------------------\n");
    }
    printf("THANK YOU!!\n");
    printf("--------------------------------------\n");

}

int Delete_detailOfstu(struct Student_details *ptr , int index)
{
    int flag = 1;
    getchar();
    if(index==0)
    {
        printf("--------------------------------------\n");
        printf("There is no existing list of Student Details.\n");
        printf("THANK YOU!!\n");
        printf("--------------------------------------\n");
        return 0;
    }
    char delID[8];
    printf("--------------------------------------\n");
    printf("Enter that ID , which's details Do you want to delete!!\n\n");
    printf("Enter ID :");
    scanf("%s",delID);
    for(int i=0 ; i<index ; i++)
    {
        if(strcmp(delID,(ptr+i)->stuID)==0)
        {
            for(int j=i ; j<index ; j++)
            {
                ptr[j]=ptr[j+1];
            }
            flag=0;
        }
        
        
    }
    if(flag)
    {
        printf("No Such ID Found!!");
        printf("THANK YOU!!\n");
        printf("--------------------------------------\n");
        return 0;
    }
    index=index-1;
    PrintingDetails_inFile(ptr,index);
    printf("\nDetails Deleted Successfuly!!\n");
    printf("THANK YOU!!\n");
    printf("--------------------------------------\n");
    return index;

}


void Search_stuDetails(struct Student_details *ptr,int total_stu)
{
    int flag=1;
    getchar();
    if(total_stu==0)
    {
        printf("----------------------------------------\n");
        printf("There is no existing list of Student Details>\n");
        printf("\nTHANK YOU!!\n");
        printf("--------------------------------------\n");

    }
    else
    {
        char id[8];
        printf("----------------------------------------\n");
        printf("Now You Can Search Any Student's Details\n");
        printf("               Via Student ID\n\n");
        printf("Enter ID:");
        scanf("%s",id);
        for(int i=0 ; i<total_stu ; i++)
        {
            if(strcmp(id,(ptr+i)->stuID)==0)
            {
                printf("Name : ");
                puts((ptr+i)->stuName);
                printf("\n");
                printf("ID: ");
                puts((ptr+i)->stuID);
                printf("\n");
                printf("Marks of Maths: %f\n",(ptr+i)->math_marks);
                printf("Marks of CCP  : %f\n",(ptr+i)->ccp_marks);
                printf("Marks of BEEE : %f\n",(ptr+i)->beee_marks);
                printf("Total Marks   : %f\n",(ptr+i)->total);
                printf("--------------------------------------\n");
                flag=0;
            }
            
        }
        if (flag)
        {
            printf("\nThere is no such ID.\n");
        }
        printf("\nTHANK YOU!!\n");
        printf("--------------------------------------\n");
    }
}

void PrintingFinalDetails_inFile(struct Student_details *ptr ,int total_stu)
{
    FILE *fptr;
    fptr = fopen("Final_stu_record.txt","a");
    for(int i=0 ; i<total_stu ; i++)
    {
        fputs((ptr+i)->stuID , fptr );
        fprintf(fptr ,"\t\t\t");
        fprintf(fptr , "%s" , (ptr+i)->stuName);
        fprintf(fptr ,"\t\t");
        fprintf(fptr,"%f\t\t",(ptr+i)->math_marks);
        fprintf(fptr,"%f\t\t",(ptr+i)->ccp_marks);
        fprintf(fptr,"%f\t\t",(ptr+i)->beee_marks);
        fprintf(fptr,"%f\n",(ptr+i)->total);
    }
    fclose(fptr);
}