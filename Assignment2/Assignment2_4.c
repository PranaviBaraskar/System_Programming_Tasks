
////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//    PROBLEM STATEMENT : 4. Write a program which accept directory name from user and print 
//                            all file,names and its types from that directory.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Diplay all Files from directory and its Types.
//    INPUT             :   Directory Name.
//    OUTPUT            :   Display File And Its Types.
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
    struct stat sobj;
    if(argc != 2)
    {
        printf("Invalid parameter\n");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char Path[100] = {'\0'};
    char Name[50];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("There is no file \n");
        return -1;
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("\nList of Files in %s : \n\n",argv[1]);
    printf("---------------------------------------------------------------------------------\n");
    printf("File Names \t\tiNode Numbers\t\tFileType\n");
    printf("---------------------------------------------------------------------------------\n");
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path,"%s/%s", argv[1], entry->d_name);
        stat (Path,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            strcpy(Name,"Regular");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            strcpy(Name,"Directory");
        }

        printf("%10s\t:\t%lld\t:\t%s File\n",entry->d_name,entry->d_ino,Name);
        printf("-----------------------------------------------------------------------------\n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment2_4.c -o Assignment2_4
//                  ./Assignment2_4 Demo
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//