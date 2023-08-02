
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  5 : Write a program which creates static library which contains file 
//                             name from user and which displays the information of that file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------* SHARED FILE *------------------------------------------//

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include"Assignment7_5.h"

#define BOLCK_SIZE 1024

void InfoFile(char *FileName)
{
    int fd = 0;
    struct stat sobj;

    fd = open(FileName, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return;
    }
    else
    {
        printf("Successfully opened...\n");
    }

    fstat(fd,&sobj);

    printf("File Name \t\t:\t %s\n",FileName);
    printf("File Size \t\t:\t %lld\n",sobj.st_size);
    printf("File INode Number \t:\t %llu\n",sobj.st_ino);
    printf("File Block \t\t:\t %lld\n",sobj.st_blocks);
    printf("File Link \t\t:\t %d\n",sobj.st_nlink);

}
