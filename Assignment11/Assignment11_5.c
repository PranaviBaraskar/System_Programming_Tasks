// Pending code..

/////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : 5. Write a program which creates two threads by 
//                      using pthread API, where one thread count number of 
//                      capital characters from demo.txt file and other threads 
//                      count number of small characters from same file.
//
/////////////////////////////////////////////////////////////////////////////

//==========================================================================

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BLOCK 1024

//==========================================================================

void *ThreadProc1(void *ptr)
{
    int fd = *(int *)ptr;
    char Buffer[BLOCK] = {'\0'};
    int iCnt = 0;
    int ret = 0;
    int iCountCap = 0;

    while ((ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < ret; iCnt++)
        {
            if ((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
            {
                iCountCap++;
            }
        }
    }

    pthread_exit(iCountCap);
}

//==========================================================================

void *ThreadProc2(void *ptr)
{
    int fd = *(int *)ptr;
    char Buffer[BLOCK] = {'\0'};
    int iCnt = 0;
    int ret = 0;
    int *iCountSmall = 0;

    while ((ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        for (iCnt = 0; iCnt < ret; iCnt++)
        {
            if ((Buffer[iCnt] >= 'a') && (Buffer[iCnt] <= 'z'))
            {
                (*iCountSmall)++;
            }
        }
    }

    pthread_exit(iCountSmall);
}

//==========================================================================

//-----------------------------*** MAIN FUNCTION ***--------------------------

int main()
{
    pthread_t TID1, TID2;
    int Ret = 0;
    int fd = 0;
    void *CapRet = NULL;
    void *SmallRet = NULL;

    fd = open("Demo.txt", O_RDONLY);
    printf("fd : %d\n", fd);
    if (fd  == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    Ret = pthread_create(&TID1,
                         NULL,
                         ThreadProc1,
                         (void *)&fd);
    if (Ret != 0)
    {
        printf("Unable to create a thread\n");
        return -1;
    }

    Ret = pthread_create(&TID2,
                         NULL,
                         ThreadProc2,
                         (void *)&fd);
    if (Ret != 0)
    {
        printf("Unable to create a thread\n");
        return -1;
    }

    pthread_join(TID1, &CapRet);
    pthread_join(TID2, &SmallRet);

    printf("Capital Letters in Demo.txt is : %d\n",CapRet);
    printf("Small Letters in Demo.txt is : %d\n",SmallRet);

    printf("End of Main Thread\n");
    pthread_exit(NULL);

    return 0;
}

//--------------------------*** END OF PROGRAM ***--------------------------

//==========================================================================
