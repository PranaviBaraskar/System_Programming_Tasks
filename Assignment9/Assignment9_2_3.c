
//====================================================================================================

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK 1024

//-------------------------------------*  MAIN FUNCTION  *----------------------------------------------------

int main()
{
    printf("Child Process with PID : %d\n",getpid());

    int fd = 0, fd1 = 0;
    int ret = 0;
    char Buffer[BLOCK] = {'\0'};
    int iCnt = 0;
    int iCountCap = 0;
    char str[50];
    char Count[5];

    fd = open("Hello.txt",O_RDONLY);
    if(fd != 3)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    fd1 = open("Count.txt",O_RDWR | O_APPEND);
    if(fd1 == -1)
    {
        fd1 = 0;
        fd1 = creat("Count.txt",0777);
    }

    while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(iCnt = 0; iCnt <= ret; iCnt++)
        {
            if((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
            {
                iCountCap++;
            }
        }
    }

    sprintf(Count,"%d",iCountCap);
    strcpy(str,"Captial Letters in Hello.txt is : ");
    strcat(str,Count);
    
    write(fd1, str, sizeof(str));

    return 0;
}
//----------------------------------------------------------------------------------------------------
//
//      Compilation Commad :  gcc Assignment9_2_3.c -o ChildProcess2
//
//====================================================================================================