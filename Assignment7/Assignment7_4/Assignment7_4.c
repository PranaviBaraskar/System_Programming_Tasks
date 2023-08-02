
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  4 : Write a program which create shared library which internally loads other shared library.
//
//                              The inner shared library provides the function to calculate the factorial of number.
//                              Also write a program which will load that shared library and call the function.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------* SHARED FILE *------------------------------------------//

#include<stdio.h>
#include"Assignment7_4.h"

int Factorial(int iNo)
{
    int iFact = 1;
    int iCnt = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact = iFact * iCnt;
    }
    return iFact;
}
int main()
{
    int iValue = 5;
    Factorial(iValue);

    return 0;
}