/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 3. Write a program which creates single thread and we 
//           have to pass parameter to that thread from main thread.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * threadproc(void *ptr)
{
    int i = (int)ptr;
    int iCnt = 0;

    for(iCnt = 1; iCnt <= i; iCnt++)
    {
        printf("*\t");
    }
    printf("\n");
}

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    int ret = 0;
    pthread_t TID;
    int iValue = 10;

    ret = pthread_create(&TID,
                          NULL,
                          threadproc,
                          (int *)iValue);
    if(ret != 0)
    {
        printf("Unable to create a thread\n");
    }

    printf("Thread ID : %d\n",TID);
    pthread_join(TID,NULL);

    return 0;
}
//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================