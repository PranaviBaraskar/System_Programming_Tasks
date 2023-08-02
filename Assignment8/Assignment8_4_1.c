//=============================================================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      PROBLEM STATEMENT : 3. Write a program which creates two processes as process2 and process3 and 
//                              our parent process terminates till both the processes terminates.
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
        execl("./ChildProcess2",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
        Cpid = wait(&EXIT_STATUS);
        printf("Child Process 2 Terminated with PID : %d and Exit status : %d\n",Cpid,EXIT_STATUS);
    }
    

    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess3",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
        Cpid = wait(&EXIT_STATUS);
        printf("Child Process 3 Terminated with PID : %d and Exit status : %d\n",Cpid,EXIT_STATUS);
    }
    
    return 0;
}

//=============================================================================================================