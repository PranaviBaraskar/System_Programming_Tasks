
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   5. Write a program which accept file name and position 
//                              from user and read 20 bytes from that position.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct Employee_Info
{
    char Name[50];
    int ID_number;
    int Age;
    char city[20];
    char Feild[10];
    long int Mobile_number;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Write information of Employee in structure
//    INPUT             :   Info of Employee
//    OUTPUT            :   output is in Assignment5_2_1.
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
    struct Employee_Info obj;
    int fd = 0;
    int iNo = 0;
    char FName[50] = {'\0'};

    strcpy(obj.Name,"Anvay");
    obj.ID_number = 78;
    obj.Age = 31;
    obj.Mobile_number = 7774773778;
    strcpy(obj.city,"Mumbai");
    strcpy(obj.Feild,"IT");

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
//      Command :   gcc Assignment5_2.c -o Assignment5_2
//                  ./Assignment5_2 Employee.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//