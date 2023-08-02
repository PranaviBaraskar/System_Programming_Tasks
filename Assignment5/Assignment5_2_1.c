
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   2. Write a program which accept file name from user which contains 
//                          information of emloyee, we have to read all contents of that file.
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
    char Field[10];
    long int Mobile_number;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Read information of Employee from structure
//    INPUT             :   Information of Employee.
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
    struct Employee_Info obj;
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
    printf("ID Number      \t\t:\t %d\n",obj.ID_number);
    printf("-------------------------------------------------------------\n");
    printf("Age    \t\t\t:\t %d\n",obj.Age);
    printf("-------------------------------------------------------------\n");
    printf("Mobile_number     \t\t:\t %ld\n",obj.Mobile_number);
    printf("-------------------------------------------------------------\n");
    printf("Field     \t\t:\t %s\n",obj.Field);
    printf("-------------------------------------------------------------\n");
    printf("city     \t\t:\t %s\n",obj.city);
    printf("-------------------------------------------------------------\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment5_2_1.c -o Assignment5_2_1
//                  ./Assignment5_2_1 Employee.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//