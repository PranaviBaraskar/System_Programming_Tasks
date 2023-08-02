
//====================================================================================================

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside Child Process 2 with PID : %d\n",getpid());
    printf("Inside Child Process 2 with Parent PID : %d\n",getppid());

    return 0;
}

//----------------------------------------------------------------------------------------------------
//
//      Compilation Commad :  gcc Assignment8_4_3.c -o ChildProcess2
//
//====================================================================================================