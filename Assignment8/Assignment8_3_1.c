//=============================================================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      PROBLEM STATEMENT : 3. Write a program which creates three different processes 
//                              internally as process2, process3, process4.
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
        execl("./ChildProcess2",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
    }

    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess3",NULL,NULL);
    }

    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess4",NULL,NULL);
    }
    
    return 0;
}

//=============================================================================================================