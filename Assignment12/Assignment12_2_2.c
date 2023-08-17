///////////////////////////////////////////////////////////////////////////////////////
//
//      APPLICATION OF CILENT
//
///////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

///////////////////////////////////////////////////////////////////////////////////////
//
//      MAIN FUNCTION ---
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char *ptr = NULL;
    int iCnt = 0;

    shmid = shmget(Key, shmsize,0666);
    if(shmid == 0)
    {
        printf("Share Memory Sucessfully allocated the memory...\n");
    }

    ptr = shmat(shmid,NULL,0);
    if(ptr == NULL)
    {
        printf("Unable to Attach Shared Memory\n");
    }

    printf("Data from shared memory is : \n");
    while(*ptr != '\0')
    {
        printf("%c",*ptr);
        ptr++;
    }

    return 0;
}
//=====================================================================================