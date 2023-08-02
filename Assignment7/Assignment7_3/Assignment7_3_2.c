
//--------------------------------------* SHARED FILE *------------------------------------------//

//--------------------------*~ CHECK WETHER THE NUMBER IS PERFECT OR NOT...

#include<stdio.h>
#include<stdbool.h>
#include"Assignment7_3_2.h"

bool CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;
    bool flag = true;

    for(iCnt = 1;iCnt <= (iNo/2); iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }

    if(iSum == iNo)
    {
        return flag;
    }
    else
    {
        flag = false;
        return flag;
    }
    
}
int main()
{
    int iValue = 28;
    CheckPerfect(iValue);


    return 0;
}