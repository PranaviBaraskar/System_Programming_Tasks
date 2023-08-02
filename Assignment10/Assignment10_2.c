/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 2. Write a program which creates two thread, 
//                      first thread print numbers from
//                      1 to 500 & other thread print the numbers from 500 to 1.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * Threadproc1(void *)
{
    int iCnt = 0;
    printf("Number's from Thread 1 : \n");
    for(iCnt = 1; iCnt <= 500; iCnt++)
    {
        printf("|%d|\t",iCnt);
    }
    printf("\n");
}

void * Threadproc2(void *)
{
    int iCnt = 0;
    printf("Number's from Thread 2 : \n");
    for(iCnt = 500; iCnt >= 1; iCnt--)
    {
        printf("|%d|\t",iCnt);
    }
    printf("\n");
}

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    int ret1 = 0;
    int ret2 = 0;

    pthread_t TID1;
    pthread_t TID2;

    ret1 = pthread_create(&TID1,
                          NULL,
                          Threadproc1,
                          NULL);
    if(ret1 != 0)
    {
        printf("Unable to create a thread\n");
    }

    printf("Thread ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,
                          NULL,
                          Threadproc2,
                          NULL);
    if(ret2 != 0)
    {
        printf("Unable to create a thread\n");
    }

    printf("Thread ID : %d\n",TID2);

    return 0;
}

//-------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================