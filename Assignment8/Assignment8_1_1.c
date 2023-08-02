//=============================================================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      PROBLEM STATEMENT : Write a program in which parent process waits till its child process terminates.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//-------------------------------------*  MAIN FUNCTION  *----------------------------------------------------

int main()
{
    int Ret = 0;
    int Cpid = 0;
    int EXIT_STATUS = 0;

    Ret = fork();

    if(Ret == 0)
    {
        execl("./ChildProcess",NULL,NULL);
    }
    else 
    {
        printf("Parent process is running with PID : %d\n",getpid());
        Cpid = wait(&EXIT_STATUS);
        printf("Child process Terminated having PID : %d, and Exit Status : %d\n",Cpid,EXIT_STATUS);
    }

    return 0;
}

//=============================================================================================================