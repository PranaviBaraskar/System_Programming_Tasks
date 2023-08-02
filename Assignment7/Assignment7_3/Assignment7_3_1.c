
//--------------------------------------* SHARED FILE *------------------------------------------//

//--------------------------*~ CHECK WETHER THE NUMBER IS PRIME OR NOT...

#include<stdio.h>
#include<stdbool.h>
#include"Assignment7_3_1.h"

bool CheckPrime(int iNo)
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 2;iCnt < iNo; iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int main()
{
    int iValue = 7;

    CheckPrime(iValue);

    return 0;
}