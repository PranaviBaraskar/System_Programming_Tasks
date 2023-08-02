
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :   3. Write a program which accept directory name from user and 
//                              write information of all regular.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

#pragma pack(1)
struct File_Info
{
   char File_Name[20];
   int File_Size;
   int File_Link;
   int iNode_number;
   int File_Block;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//     MAIN FUNCTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Inavlid arguments \n");
        return -1;
    }
    
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char Path[30];
    struct File_Info fobj;
    struct stat sobj;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Enable to open directory\n");
        return -1;
    }

    fd = creat("FileInformation",0777);
    if(fd == -1)
    {
        printf("Unable to create file \n");
        return-1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path,"%s/%s",argv[1],entry->d_name);
        stat(Path, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            fobj.File_Size = sobj.st_size;
            fobj.File_Link = sobj.st_nlink;
            fobj.iNode_number = sobj.st_ino;
            fobj.File_Block = sobj.st_blocks;
            strcpy(fobj.File_Name,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
        }
    }

    closedir(dp);
    
    return 0;
}

//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//