///////////////////////////////////////////////////////////////////////////////////////
//
//  PROBLEM STATEMENT : Write a program which performs interprocess communication 
//                      using the concept of message queue.
//
///////////////////////////////////////////////////////////////////////////////////////

//========================================== APPLICATION OF SERVER :

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/msg.h>

#define MAX_TEXT 512

struct my_msg_st
{
    long int my_msg_type;
    char Some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    int msgid = 0;

    struct my_msg_st some_data;
    char buffer[BUFSIZ];

    printf("Demonstration of IPC using Message Queue\n");
    printf("Server Process is Running\n");

    msgid = msgget((key_t)1234, IPC_CREAT | 0666);
    if(msgid == -1)
    {
        printf("Failed to create : \n");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue is created successfully\n");

    while(running)
    {
        printf("Enter Some Message : ");
        fgets(buffer,BUFSIZ,stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.Some_text,buffer);

        if(msgsnd(msgid, (void*) &some_data, MAX_TEXT,0) == -1)
        {
            printf("msgsnd failed\n");
            exit(EXIT_FAILURE);
        }

        if(strncmp(buffer,"end",3) == 0)
        {
            running = 0;
            printf("Terminating the server Process\n");
            exit(EXIT_SUCCESS);
        }
    }
}
//=====================================================================================