
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 4. Write a program which accept file name from user and print 
//                              all information about that file.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Display All Information about the File
//    INPUT             :   File Name
//    OUTPUT            :   Information of Given File name.
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
    if(argc != 2)
    {
        printf("Please enter valid Parametes..\n");
        return -1;
    }

    int fd = 0;
    struct stat sobj;

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

    fstat(fd,&sobj);

    printf("---------------------------------------------------------\n\n");
    printf("Information of File : %s\n\n",argv[1]);
    printf("---------------------------------------------------------\n");
    printf("File Name \t\t:\t %s\n",argv[1]);
    printf("---------------------------------------------------------\n");
    printf("File Inode Number \t:\t %llu\n",sobj.st_ino);
    printf("---------------------------------------------------------\n");
    printf("File Size \t\t:\t %lld\n",sobj.st_size);
    printf("---------------------------------------------------------\n");
    printf("File Mode \t\t:\t %d\n",sobj.st_mode);
    printf("---------------------------------------------------------\n");
    printf("File Block \t\t:\t %lld\n",sobj.st_blocks);
    printf("---------------------------------------------------------\n");
    printf("File link \t\t:\t %d\n",sobj.st_nlink);
    printf("---------------------------------------------------------\n");

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment1_4.c -o Assignment1_4
//                  ./Assignment1_4 Demo.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//