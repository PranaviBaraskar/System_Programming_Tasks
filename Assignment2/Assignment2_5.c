
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  5. Write a program which accept directory name from user and
//                             print name of such a file having largest size
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
//    DESCRIPTION       :   Find the largest File in Directory
//    INPUT             :   Directory Name.
//    OUTPUT            :   Display Largest Regular File.
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
    int iMax = 0;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("There is no file \n");
        return -1;
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("\nList of Files which is in %s : \n\n",argv[1]);
    printf("---------------------------------------------------------------------------------\n");
    printf("File Names\t\tFile Size\n");
    printf("---------------------------------------------------------------------------------\n");
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(Path, "%s/%s", argv[1], entry->d_name);
        stat (Path,&sobj);
        if(iMax < (sobj.st_size))
        {
            iMax = sobj.st_size;
            strcpy(Name,entry->d_name);
        }
    }
    printf("%s File\t:\t%d\n",Name,iMax);
    printf("-----------------------------------------------------------------------------\n");
    
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment2_5..c -o Assignment2_5
//                  ./Assignment2_5 Demo
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//