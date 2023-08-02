
//-------------------------------* CLIENT FILE *-----------------------------------//

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int,int) = NULL;
    int iRet = 0;
    int iValue1 = 0;
    int iValue2 = 0;

    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load the library \n");
    }

    printf("Enter the Value First Value : \n");
    scanf("%d",&iValue1);

    printf("Enter the Value Second Value : \n");
    scanf("%d",&iValue2);

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of funtion\n");
        return -1;
    }

    iRet = fptr(iValue1, iValue2);
    printf("Addition is : %d\n",iRet);

    fptr = dlsym(ptr,"Subtraction");
    if(fptr == NULL)
    {
        printf("Unable to load the address of funtion\n");
        return -1;
    }

    iRet = fptr(iValue1, iValue2);
    printf("Subtraction is : %d\n",iRet);

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load the address of funtion\n");
        return -1;
    }

    iRet = fptr(iValue1, iValue2);
    printf("Multipilction is : %d\n",iRet);

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("Unable to load the address of funtion\n");
        return -1;
    }

    iRet = fptr(iValue1, iValue2);
    printf("Division is : %d\n",iRet);

    return 0;
}