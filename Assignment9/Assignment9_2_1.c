//=============================================================================================================

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      PROBLEM STATEMENT : 2. Write a program which creates two processes.
//                          Process 1 count number of capital characters from demo.txt file.
//                          And process 2 count number of capital characters from hello.txt file.
//                          Both the processes writes its count in count.txt file.
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
        execl("./ChildProcess1",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
    }

    Ret = fork();
    if(Ret == 0)
    {
        execl("./ChildProcess2",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
    }
    
    return 0;
}

//=============================================================================================================