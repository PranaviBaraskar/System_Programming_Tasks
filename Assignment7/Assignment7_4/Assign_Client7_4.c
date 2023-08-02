
//-------------------------------* CLIENT FILE *-----------------------------------//

#include<stdio.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int) = NULL;
    int iValue = 0;
    int Ret = 0;

    ptr = dlopen("Library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to Load the Library\n");
    }

    fptr = dlsym(ptr,"Factorial");
    if(fptr == NULL)
    {
        printf("Unable to load the Function\n");
    }
    
    printf("Enter the number\n");
    scanf("%d",&iValue);

    Ret = fptr(iValue);

    printf("Factorial of %d is : %d\n",iValue,Ret);
    

    return 0;
}