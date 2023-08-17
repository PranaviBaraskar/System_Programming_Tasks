///////////////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : Write a program which creates one child process, child process 
//                      write something in unnamed pipe and parent process read the 
//                      data from that pipe.
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

///////////////////////////////////////////////////////////////////////////////////////
//
//      MAIN FUNCTION ---
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int FD[2];
    int Ret = 0;
    char Arr[] = "India is my Country";
    char Buffer[512];

    Ret = fork();

    if(Ret == 0)                 // Child Process
    {
        printf("Child Process is schedule for writhing the data into the pipe...\n");
        close(FD[0]);
        write(FD[1],Arr,strlen(Arr));
        exit(0);
    }
    else                         // Parent Process
    {
        printf("Parent Process is schedule fro Reading the data from the pipe...\n");
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));
    }
    printf("Data from PIPE is : \n%s\n",Buffer);
    
    return 0;
}

//=====================================================================================