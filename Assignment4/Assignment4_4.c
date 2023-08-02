
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   4. Write a program which accept directory name from user and copy 
//                             first 10 bytes from all regular files into newly created file 
//                                  named as Demo.txt.
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
//    DESCRIPTION       :   copy first 10 bytes from all file present in directory.
//    INPUT             :   Directory Name.
//    OUTPUT            :   copied all 10bytes
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
    if(argc != 2)
    {
        printf("Inavlid Arguments \n");
        return -1;
    }

    int fd1 = 0; 
    int fd2 = 0;
    int ret = 0;
    int ret1 = 0;
    char Buffer[BLOCKSIZE] = {'\0'};
    char Path[50] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    fd1 = creat("Demo.txt",0777);
     if(fd1 == -1)
     {
         printf("Unable to create new file\n");
         return -1;
    }

    fd1 = open(argv[2],O_RDWR);
    if(ret1 == -1)
    {
        printf("Unable to open new file\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path,"%s/%s",argv[1],entry->d_name);
        fd2 = open(Path,O_RDONLY);
        if(fd2 == -1)
        {
            printf("Unable to open file in directory\n");
        }
        ret = read(fd2,Buffer,10);
        printf("%s\n",Buffer);
        write(fd1,Buffer,10);
        close(fd2);
    }

    closedir(dp);
    close(fd1);

    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment4_4.c -o Assignment4_4
//                  ./Assignment4_4 Hello
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//