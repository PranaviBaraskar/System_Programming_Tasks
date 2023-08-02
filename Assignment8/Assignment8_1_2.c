
//====================================================================================================

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("Inside child Process - PID of parent process is %d\n",getppid());

    return 0;
}

//----------------------------------------------------------------------------------------------------
//
//      Compilation Commad :  gcc Assignment8_1_2.c -o ChildProcess
//
//====================================================================================================