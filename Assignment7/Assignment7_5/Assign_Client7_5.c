
//-------------------------------* CLIENT FILE *-----------------------------------//

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include"Assignment7_5.h"

int main()
{
    char FileName[50] = {'\0'};

    printf("Enter the file name to get the information \n");
    scanf("%s",FileName);

    InfoFile(FileName);

    return 0;
}