
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 1. Write a program which accept file name from user and read whole file.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Open And Whole File given by user
//    INPUT             :   File Name.
//    OUTPUT            :   Read Regular File and Display it on Screen.
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   14.7.2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Please enter valid Parametes..\n");
        return -1;
    }

    int fd = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    fd = open(argv[1],O_RDONLY);
    if(fd == 3)
    {
        printf("Successfully opened..\n");
    }
    else if(fd == -1)
    {
        printf("Unable to open Regular file..\n");
        return -1;
    }

    printf("------------------------------------------------------\n");
    printf("Read whole file %s : \n",argv[1]);
    printf("------------------------------------------------------\n");

    while((Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        write(1,Buffer,sizeof(Buffer));
    }
    printf("\n------------------------------------------------------\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment2_1.c -o Assignment2_1
//                  ./Assignment2_1 Demo.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//