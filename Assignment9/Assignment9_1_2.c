
//====================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

//-------------------------------------*  MAIN FUNCTION  *----------------------------------------------------

int main()
{
    printf("Child Process with PID : %d\n",getpid());

    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char FileName[50] = {'\0'};
    char Path[50];
    int iCount = 0;

    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create the file\n");
    }

    dp = opendir("Desktop");
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path,"%s/%s","Hello",entry->d_name);
        stat(Path,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            strcpy(FileName,entry->d_name);
            write(fd,FileName,sizeof(FileName));
        }
    }

    closedir(dp);

    return 0;
}

//----------------------------------------------------------------------------------------------------
//
//      Compilation Commad :  gcc Assignment9_1_2.c -o ChildProcess
//
//====================================================================================================