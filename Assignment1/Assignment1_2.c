
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  2. Write a program which accept file name and mode 
//                            from user and then open that file in specified mode.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Open file in specific mode which is given by the user
//    INPUT             :   File Name And Mode
//    OUTPUT            :   Open File with spcific Mode
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   13.7.2023
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
        printf("Please enter valid Parametes..\n");
        return -1;
    }

    int fd = 0;
    int mode = 0;

    if(strcmp(argv[2],"read") == 0)
    {
        mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"read+write") == 0)
    {
        mode = O_RDWR;
    }

    fd = open(argv[1],mode);
    if(fd == 3)
    {
        printf("Successfully opened..\n");
    }
    else if(fd == -1)
    {
        printf("Unable to open Regular file..\n");
        return -1;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment1_2.c -o Assignment1_2
//                  ./Assignment1_2 Demo.txt (read/write/read+write)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//