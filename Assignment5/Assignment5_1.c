
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
//    DESCRIPTION       :   read information of student from structure
//    INPUT             :   Information of student.
//    OUTPUT            :   Fetch the data from structure
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

    strcpy(obj.Name,"Pranavi");
    obj.Standard = 5;
    obj.Section = 'B';
    obj.Age = 13;
    obj.Marks = 77;
    strcpy(obj.Result,"Pass");

    strcpy(obj1.Name,"Sonal");
    obj1.Standard = 7;
    obj1.Section = 'A';
    obj1.Age = 15;
    obj1.Marks = 57;
    strcpy(obj1.Result,"Pass");

    printf("Enter the Name that you want to store all data \n");
    scanf("%s",FName);

    fd = creat(FName,0777);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
    }

    write(fd,&obj,sizeof(obj));
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment5_1.c -o Assignment5_1
//                  ./Assignment5_1 Student.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//