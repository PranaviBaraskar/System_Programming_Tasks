//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  3 .Write a program which is used to create 2 shared libraries and 
//                            that library should be loaded at run time by the other program.
//                          
//                              First Library should contains function to check whether 
//                              the input number is prime or not.
//                              Second Library should contains function to check whether 
//                              the input number is perfect or not.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------* CLIENT FILE *-----------------------------------//

#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    bool (*fptr)(int) = NULL;
    int iValue = 0;
    bool Ret = false;

    ptr = dlopen("PrimeLibrary.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to Load the Library\n");
    }

    fptr = dlsym(ptr,"CheckPrime");
    if(fptr == NULL)
    {
        printf("Unable to load the Function\n");
    }
    
    printf("Enter the number to check Whether its Prime or Not\n");
    scanf("%d",&iValue);

    Ret = fptr(iValue);
    if(Ret == true)
    {
        printf("%d is a Prime Number...\n",iValue);
    }
    else
    {
        printf("%d is a not Prime Number...\n",iValue);
    }

    ptr = dlopen("PerfectLibrary.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to Load the Library\n");
    }

    fptr = dlsym(ptr,"CheckPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load the Function\n");
    }
    
    printf("Enter the number to check Whether its Perfect or Not\n");
    scanf("%d",&iValue);

    Ret = fptr(iValue);
    if(Ret == true)
    {
        printf("%d is a Perfect Number...\n",iValue);
    }
    else
    {
        printf("%d is a not Perfect Number...\n",iValue);
    }

    return 0;
}