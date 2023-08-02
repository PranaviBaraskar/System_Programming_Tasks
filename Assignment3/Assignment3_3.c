
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 3. Write a program which accept two directory names from user and move all 
//                              files from source directory to destination directory.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Transfer Files from one to another.
//    INPUT             :   Source Directory Name And Destination Directory Name.
//    OUTPUT            :   All files from Source directory are tranferd into Destination directory
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
    if(argc != 3)
    {
        printf("Invalid parameters\n");
        return -1;
    }
    
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int Check = 0;
    char OldName[50] = {'\0'};
    char NewName[50] = {'\0'};

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp))!= NULL)
    {
        sprintf(OldName,"%s/%s",argv[1],entry->d_name);
        sprintf(NewName,"%s/%s",argv[2],entry->d_name);

        rename(OldName,NewName);
    }

    printf("Files are successfully transfered\n");

    closedir(dp);
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment3_3.c -o Assignment3_1
//                  ./Assignment3_3 Source_File_Name Destination_File_Name
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//