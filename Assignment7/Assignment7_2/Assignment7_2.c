//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  2. Write a program which is used to create shared library and
//                             that library should be loaded at run time by the other program.
//
//                             That Library should contains function which accepts 2 file names from user 
//                             and it will compare the contents of that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------* SHARED FILE *------------------------------------------//

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include"Assignment7_2.h"

#define BOLCK_SIZE 1024

int CompareFiles(char *str, char *dest)
{
    int fd1 = 0;
    int fd2 = 0;
    int Ret = 0;
    char Buffer1[BOLCK_SIZE];
    char Buffer2[BOLCK_SIZE];
    int Result = 0;

    fd1 = open(str, O_RDONLY);
    fd2 = open(dest, O_RDONLY);
    if((fd1 == -1) && (fd2 == -1))
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else
    {
        printf("Successfully opened...\n");
    }

    while((Ret = read(fd1,Buffer1,sizeof(Buffer1) != 0)))
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2)!= 0);
        if(memcmp(Buffer1,Buffer1,Ret) != 0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        Result = 1;
    }
    else
    {
        Result = -1;
    }
    return Result;
}

int main()
{
    char Arr[50];
    char Brr[50];

    CompareFiles(Arr,Brr);
}