////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 4. Write a program which accept directory name from user and 
//                              delete all such files whose size is greater than 100 bytes.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    char Path[30];
    char DirName[20];
    
    struct stat sobj;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open Directory \n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path,"%s/%s",argv[1],entry->d_name);
        stat(Path,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size >= 100)
            {
                remove(Path);
            }
        }
    }

    closedir(dp);
    
    return 0;
}