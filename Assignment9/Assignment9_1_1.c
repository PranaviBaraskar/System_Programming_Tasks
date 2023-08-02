//=============================================================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      PROBLEM STATEMENT : 1.Write a program which creates new process which is responsible to write all file 
//                          names which are present on desktop in demo file which should be created newly.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//-------------------------------------*  MAIN FUNCTION  *----------------------------------------------------

int main()
{
    int Ret = 0;

    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
    }
    
    return 0;
}

//=============================================================================================================