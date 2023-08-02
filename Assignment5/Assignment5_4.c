////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   5. Write a program which accept file name which contains data of all file. 
//                                  We have to create all file again.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define BLOCKSIZE 1024

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    char Buffer[BLOCKSIZE];
    char Path[100];

    struct dirent *entry = NULL;
    DIR *dp = NULL;

    fd1 = creat("AllCombine.txt", 0777);
    if (fd1 == -1) 
    {
        printf("Unable to create new file\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if (dp == NULL) 
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) 
    {
        sprintf(Path, "%s/%s", argv[1], entry->d_name);

        fd2 = open(Path, O_RDONLY);
        if (fd2 == -1) 
        {
            printf("Unable to open file in directory\n");
            return -1;
        }
        while ((ret = read(fd2, Buffer, sizeof(Buffer))) > 0) 
        {
            printf("%s",Buffer);   
            write(fd1, Buffer, ret);
        }
        close(fd2);
    }

    closedir(dp);
    close(fd1);

    return 0;
}
//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//