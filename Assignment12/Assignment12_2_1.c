///////////////////////////////////////////////////////////////////////////////////////
//
//      APPLICATION OF SERVER
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
    char Message[] = "Marvellous Infosystem...!";
    int Length = strlen(Message);
    int iCnt = 0;

    shmid = shmget(Key, shmsize, IPC_CREAT | 0666);
    if(shmid == 0)
    {
        printf("Share Memory Sucessfully allocated the memory...\n");
    }

    ptr = shmat(shmid,NULL,0);
    if(ptr == NULL)
    {
        printf("Unable to Attach Shared Memory\n");
    }

    for(iCnt = 0; iCnt < Length; iCnt++)
    {
        *ptr = Message[iCnt];
        ptr++;
    }
    *ptr = '\0';

    return 0;
}
//=====================================================================================