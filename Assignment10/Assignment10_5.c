/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 5. Write a program which is used to get 
//                          thread id inside its thread function.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * threadproc(void *)
{
    int SelfID = 0;

    SelfID = pthread_self();

    printf("Self Thread ID : %d\n",SelfID);
    
    pthread_exit(NULL);
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
    pthread_join(TID,NULL);

    return 0;
}
//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================