
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 1. Write a program which accept two file names from usel 
//                           and copy the contents of an existing file into newly created file.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Create New File and Copy all data from given file
//    INPUT             :   Existing file And New file
//    OUTPUT            :   Copy all data from Exiting file to New file
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   15.7.2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid parameters\n");
        return -1;
    }

    int fdSource = 0;
    int fdDest = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    int iRet = 0;

    fdSource = open(argv[1],O_RDWR);
    if(fdSource == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to create the file \n");
        return -1;
    }

    while((iRet = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,sizeof(Buffer));
    }
    printf("File is Successfully created with copied data..\n");
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment3_1.c -o Assignment3_1
//                  ./Assignment3_1 Existing_File New_File
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//