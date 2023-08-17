
//========================================== APPLICATION OF CLIENT :

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/msg.h>

struct my_msg_st
{
    long int my_msg_type;
    char Some_text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgid = 0;

    struct my_msg_st some_data;
    long int msg_to_receive = 0;

    printf("Demonstration of IPC using Message Queue\n");
    printf("Client Process is Running\n");

    msgid = msgget((key_t)1234,0666);
    if(msgid == -1)
    {
        printf("Failed to Fetch : \n");
        exit(EXIT_FAILURE);
    }

    printf("Fetching the messages from Message Queue\n");

    while(running)
    {
        msgrcv(msgid, (void*)&some_data,BUFSIZ,msg_to_receive,0);

        printf("Received Message : %s\n",some_data.Some_text);
        if(strncmp(some_data.Some_text,"end",3) == 0)
        {
            running = 0;
            printf("Terminating the Client Process\n");
            exit(EXIT_SUCCESS);
        }
    }
}
//=====================================================================================