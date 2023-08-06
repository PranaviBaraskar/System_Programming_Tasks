/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 1. Write a program which creates 4 number of threads 
//                   and our main thread waits till all the thread terminates.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//==========================================================================

void * threadproc1(void *)
{
    printf("\n------* Inside the Thread 1 *------\n\n");
    int iCnt = 0;
    printf("Number's from Thread : \n");
    for(iCnt = 1; iCnt <= 10; iCnt++)
    {
        printf("Count from Thread 1 : %d\n",iCnt);
    }
    printf("\n");
}

//==========================================================================

void * threadproc2(void *)
{
    printf("\n------* Inside the Thread 2 *------\n\n");
    int iCnt = 0;
    printf("Number's from Thread : \n");
    for(iCnt = 1; iCnt <= 10; iCnt++)
    {
        printf("Count from Thread 2 : %d\n",iCnt);
    }
    printf("\n");
}

//==========================================================================

void * threadproc3(void *)
{
    printf("\n------* Inside the Thread 3 *------\n\n");
    int iCnt = 0;
    printf("Number's from Thread : \n");
    for(iCnt = 1; iCnt <= 10; iCnt++)
    {
        printf("Count from Thread 3 : %d\n",iCnt);
    }
    printf("\n");
}

//==========================================================================

void * threadproc4(void *)
{
    printf("\n------* Inside the Thread 4 *------\n\n");
    int iCnt = 0;
    printf("Number's from Thread : \n");
    for(iCnt = 1; iCnt <= 10; iCnt++)
    {
        printf("Count from Thread 4 : %d\n",iCnt);
    }
    printf("\n");
}

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    int ret[4];
    pthread_t TID[4];
    int iCnt = 0;

    void * (*threadproc[4])(void *);

    threadproc[0] = threadproc1;
    threadproc[1] = threadproc2;
    threadproc[2] = threadproc3;
    threadproc[3] = threadproc4;

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        ret[iCnt] = pthread_create(&TID[iCnt],
                            NULL,
                            threadproc[iCnt],
                            NULL);
        if(ret[iCnt] != 0)
        {
            printf("Unable to create a thread\n");
            return -1;
        }

        printf("Thread ID : %d\n",TID[iCnt]);
        pthread_join(TID[iCnt],NULL);
    }

    return 0;
}   
//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================