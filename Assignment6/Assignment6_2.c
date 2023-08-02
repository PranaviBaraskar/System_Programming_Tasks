////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  2.Write a program which create hole of size 1kb at the end of file.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Inavlid Argument\n");
        return -1;
    }

    int fd = 0;
    int fd1 = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

    fd = creat(argv[1],0777);
    if(fd == -1)
    {
        printf("Unable to create the file...\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file...\n");
        return -1;
    }

    for(int i = 0; i < sizeof(Buffer);i++)
    {
        Buffer[0] = '\0';
    }

    ret = write(fd1,Buffer,sizeof(Buffer));

    return 0;
}