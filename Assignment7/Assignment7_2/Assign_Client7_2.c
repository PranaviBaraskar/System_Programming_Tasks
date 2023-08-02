
//-------------------------------* CLIENT FILE *-----------------------------------//

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int *ptr = NULL;
    int(*fptr)(char*,char*) = NULL;

    char Arr[50] = {'\0'};
    char Brr[50] = {'\0'};
    int iRet = 0;

    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Cannot Load the Library...\n");
        return -1;
    }

    printf("Enter the First File Name \n");
    scanf("%s",Arr);

    printf("Enter the Second File Name \n");
    scanf("%s",Brr);

    fptr = dlsym(ptr, "CompareFiles");
    if(fptr == NULL)
    {
        printf("Cannot find the Function");
    }
    
    iRet = fptr(Arr,Brr);

    if(iRet == 1)
    {
        printf("Contents of the file are same...\n");
    }
    else
    {
        printf("Contents of the file are not same...\n");
    }

    dlclose(ptr);

    return 0;
}