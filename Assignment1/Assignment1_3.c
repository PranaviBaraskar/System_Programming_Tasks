
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 3. Write a program which accept file name and on mode and that program check whether 
//                              our process can access that file in accepted mode or not.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Check Wether the gievn mode is Accessible by File or not
//    INPUT             :   File Name and Mode
//    OUTPUT            :   Accessible the file in given mode or not.
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
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        Mode = R_OK;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        Mode = W_OK;
    }
    else if(strcmp(argv[2],"execute") == 0)
    {
        Mode = X_OK;
    }

    if(access(argv[1],Mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("you can access %s file in %s mode\n",argv[1],argv[2]);
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment1_3.c -o Assignment1_3
//                  ./Assignment1_3 Demo.txt (read/write/execute)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//