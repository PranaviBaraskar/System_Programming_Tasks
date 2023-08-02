
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :3. Write a program which accept two file names from user and 
//                          check whether contents of that two files are equal are not.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define BLOCKSIZE 1024

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Check whether files are identical or not.
//    INPUT             :   two File names.
//    OUTPUT            :   Files are Indentical or not
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   17.7.2023
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
        printf("Inavlid Arguments \n");
        return -1;
    }

    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    char Buffer1[BLOCKSIZE] = {'\0'};
    char Buffer2[BLOCKSIZE] = {'\0'};
    struct stat sobj1;
    struct stat sobj2;

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);
    if((fd == -1) || (fd == -1))
    {
        printf("Unable to open files\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are not Indentical\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memset(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Both Files are Identical\n");
    }
    else
    {
        printf("Both Files are Diffrent\n");
    }

    close(fd1);
    close(fd2);
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment4_3.c -o Assignment4_3
//                  ./Assignment4_3 Hello.txt demo.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//