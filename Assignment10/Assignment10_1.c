/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 1. Write a program which is used to create simple 
//                          thread by using pthread library.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * threadproc(void *)
{
    printf("\n------* Inside the Thread *------\n\n");
}

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    int ret = 0;
    pthread_t TID;

    ret = pthread_create(&TID,
                          NULL,
                          threadproc,
                          NULL);
    if(ret != 0)
    {
        printf("Unable to create a thread\n");
    }

    printf("Thread ID : %d\n",TID);

    return 0;
}
//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================