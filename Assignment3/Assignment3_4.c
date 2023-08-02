
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 4. Write program which accept directory name from user and delete all 
//                              empty files from that directory.
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
//    DESCRIPTION       :   Delete the empty files from directory
//    INPUT             :   Directory Name.
//    OUTPUT            :   Delete empty files
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   15.7.2023
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
        printf("Invalid parameters\n");
        return -1;
    }
    
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int Check = 0;
    struct stat sobj;
    char Name[50] = {'\0'};
    char FileName[50] = {'\0'};
    int iCount = 0;
    int iCnt = 0;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

     while((entry = readdir(dp)) != NULL)
    {
        sprintf(Name,"%s/%s",argv[1],entry->d_name);
        stat(Name,&sobj);

        if(sobj.st_size == 0)
        {
            strcpy(FileName,entry->d_name);
            iCount++;
            remove(entry->d_name);
            printf("%10s  :  Removed from %s\n",FileName,argv[1]);
        }
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment3_4.c -o Assignment3_4
//                  ./Assignment3_4 Hello Demo.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//