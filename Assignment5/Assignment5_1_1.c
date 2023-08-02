
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   1. Write a program which writes structure in file. 
//                              Structure should contains information of student.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct Student_Info
{
    char Name[50];
    int Standard;
    char Section;
    int Age;
    int Marks;
    char Result[20];
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Write information of student in structure
//    INPUT             :   Info of student
//    OUTPUT            :   output is in Assignment5_1.
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   19.7.2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    struct Student_Info obj;
    struct Student_Info obj1;
    int fd = 0;
    int iNo = 0;
    char FName[50] = {'\0'};

    printf("Enter the file name : \n");
    scanf("%s",FName);

    fd = open(FName,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
    }

    read(fd,&obj,sizeof(obj));

    printf("-------------------------------------------------------------\n");
    printf("Name of student \t:\t %s\n",obj.Name);
    printf("-------------------------------------------------------------\n");
    printf("Standard      \t\t:\t %d\n",obj.Standard);
    printf("-------------------------------------------------------------\n");
    printf("Section     \t\t:\t %c\n",obj.Section);
    printf("-------------------------------------------------------------\n");
    printf("Age    \t\t\t:\t %d\n",obj.Age);
    printf("-------------------------------------------------------------\n");
    printf("Marks     \t\t:\t %d\n",obj.Marks);
    printf("-------------------------------------------------------------\n");
    printf("Result     \t\t:\t %s\n",obj.Result);
    printf("-------------------------------------------------------------\n");
    
    close(fd);


    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment5_1_1.c -o Assignment5_1_1
//                  ./Assignment5_1_1
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//