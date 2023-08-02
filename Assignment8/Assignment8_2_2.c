
//====================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = fork();
    if(Ret == 0)
    {
        printf("Inside Child Process with PID : %d\n",getpid());
        execl("./GrandChildProcess",NULL,NULL);
    }
    else
    {
        printf("Parent Process is with PID : %d\n",getpid());
    }

    return 0;
}

//----------------------------------------------------------------------------------------------------
//
//      Compilation Commad :  gcc Assignment8_2_2.c -o ChildProcess
//
//====================================================================================================