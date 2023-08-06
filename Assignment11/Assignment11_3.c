/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 3. Write a program which is used to predict
//                           the problem due to lack of synchronization.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int Counter = 0;

//==========================================================================

void * ThreadProc1(void * ptr)
{
    int i = 0;
    Counter++;

    printf("Thread executed with counter : %d \n",Counter);

    for(i = 1; i < 0xFFFFFFFF; i++);

    printf("Thread complete with counter : %d \n",Counter);

    pthread_exit(NULL);
}

//==========================================================================

void * ThreadProc2(void * ptr)
{
    int i = 0;
    Counter++;

    printf("Thread executed with counter : %d \n",Counter);

    for(i = 1; i < 0xFFFFFFFF; i++);

    printf("Thread complete with counter : %d \n",Counter);

    pthread_exit(NULL);
}

//============================================================================

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    pthread_t TID1, TID2;
    int Ret = 0;

    Ret = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
        return -1;
    }

    Ret = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(Ret != 0)
    {
        printf("Unable to create a thread\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    pthread_exit(NULL);

    printf("End of Main Thread\n");

    return 0;
}

//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================