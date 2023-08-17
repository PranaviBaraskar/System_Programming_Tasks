///////////////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 2.Write a program which creates two processes and that 
//                      two processes can communicate with each other by using 
//                      concept of shared memory.
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

///////////////////////////////////////////////////////////////////////////////////////
//
//      MAIN FUNCTION ---
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int Ret1 = 0;
    int Ret2 = 0;

    Ret1 = fork();

    if(Ret1 == 0)
    {
        execl("./SharedMemory_Server",NULL,NULL);
    }

    Ret2 = fork();

    if(Ret2 == 0)
    {
        execl("./SharedMemory_Cilent",NULL,NULL);
    }

    return 0;
}
//=====================================================================================