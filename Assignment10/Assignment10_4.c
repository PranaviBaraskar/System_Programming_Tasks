/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 4. Write a program which creates single thread and 
//                      it accept one value from user and it return some value 
//                          to the caller thread..
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
    int iFact = 1;

    for(iCnt = 1; iCnt <= i; iCnt++)
    {
        iFact = iFact * iCnt;
    }
    
    pthread_exit(iFact);
}

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    int ret = 0;
    pthread_t TID;
    int iValue = 5;
    int iRet = 0;

    ret = pthread_create(&TID,
                          NULL,
                          threadproc,
                          (int *)iValue);
    if(ret != 0)
    {
        printf("Unable to create a thread\n");
    }

    printf("Thread ID : %d\n",TID);
    pthread_join(TID,&iRet);

    printf("Return Value of Addition of Factors : %d\n",iRet);

    return 0;
}
//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================