
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  5. Write a program which accept file name and number of 
//                            bytes from user and read that number of bytes from file.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Read data from file.
//    INPUT             :   File Name and Number of Bytes
//    OUTPUT            :   Read and Display data on screen
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   13.7.2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Please enter valid Parametes..\n");
        return -1;
    }

    int fd = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int Ret = 0;

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

    Ret = read(fd,Buffer,atoi(argv[2])); 
    if(Ret == 0)
    {
        printf("There is no data in File\n");
    } 

    printf("Read Data from file %s : %s\n",argv[1],Buffer);  

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment1_5.c -o Assignment1_5
//                  ./Assignment1_5 Demo.txt (Bytes that you to read)(10)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//