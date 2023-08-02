
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 2. Write a program which accept directory name and file name from user and 
//                              check whether that file is present in that directory or not.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Check whether The given File is present in given directory or not
//    INPUT             :   Directory name and File Name.
//    OUTPUT            :   Check file is present or not
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

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

     while((entry = readdir(dp)) != NULL)
    {
        if(entry->d_name == argv[2])
        {
            Check++;
            break;
        }
    }

    printf("%s is present in Directory %s\n",argv[2],argv[1]);
    
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment3_2.c -o Assignment3_2
//                  ./Assignment3_2 Hello Demo.txt
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//