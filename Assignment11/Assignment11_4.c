/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 4. Write a program which creates two thread , 
//                          and by using appropriate synchronization 
//                              technique avoid the scheduling problem.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//==========================================================================

int Counter = 0;
pthread_mutex_t lock;

//==========================================================================

void * ThreadProc1(void * ptr)
{
    pthread_mutex_lock(&lock);
    int i = 0;
    Counter++;

    printf("Thread executed with counter : %d \n",Counter);

    for(i = 1; i < 0xFFFFFFFF; i++);

    printf("Thread complete with counter : %d \n",Counter);

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

//==========================================================================

void * ThreadProc2(void * ptr)
{
    pthread_mutex_lock(&lock);
    int i = 0;
    Counter++;

    printf("Thread executed with counter : %d \n",Counter);

    for(i = 1; i < 0xFFFFFFFF; i++);

    printf("Thread complete with counter : %d \n",Counter);

    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

//============================================================================

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    pthread_mutex_init(&lock,NULL);
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

    pthread_mutex_destroy(&lock);

    printf("End of Main Thread\n");
    pthread_exit(NULL);

    return 0;
}

//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================