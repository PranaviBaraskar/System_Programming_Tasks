
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT : 3. Write a program which accept directory name from 
//                            user and print all file names from that directory.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    DESCRIPTION       :   Print All Regular File names from Directory
//    INPUT             :   Directory Name.
//    OUTPUT            :   Display All Regular File.
//    AUTHOR            :   Pranavi Ghanshyaam Baraskar
//    DATE              :   14.7.2023
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
        printf("Invalid parameter\n");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("There is no file \n");
        return -1;
    }
    printf("--------------------------------------------------------\n");
    printf("\nList of Files in %s : \n\n",argv[1]);
    printf("--------------------------------------------------------\n");
    printf("File Names \t\tiNode Numbers\n");
    printf("--------------------------------------------------------\n");
    while((entry = readdir(dp)) != NULL)
    {
        printf("%10s\t:\t%lld\n",entry->d_name,entry->d_ino);
        printf("--------------------------------------------------------\n");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Command :   gcc Assignment2_3.c -o Assignment2_3
//                  ./Assignment2_3 Demo
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------* END_OF_THE_PROGRAM *-------------------------------------------------//