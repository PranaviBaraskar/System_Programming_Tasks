//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    PROBLEM STATEMENT :  1 : Write a program which is used to create shared library and that 
//                             library should be loaded at run time by the other program.
//
//                             That Library should contains functions to perform the arithmetic operations like addition,
//                             Subtraction, Division and multiplication.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//--------------------------------------* SHARED FILE *------------------------------------------//

#include<stdio.h>
#include"Assignment7_1.h"

int Addition(int iNo1, int iNo2)
{
    int iSum = 0;

    iSum = iNo1 + iNo2;
    return iSum;
}

int Subtraction(int iNo1, int iNo2)
{
    int iSum = 0;

    iSum = iNo1 - iNo2;
    return iSum;
}

int Multiplication(int iNo1, int iNo2)
{
    int iSum = 1;

    iSum = iNo1 * iNo2;
    return iSum;
}

int Division(int iNo1, int iNo2)
{
    int iSum = 1;

    iSum = iNo1 / iNo2;
    return iSum;
}

int main()
{
    int iValue1 = 0;
    int iValue2 = 0;

    Addition(iValue1,iValue2);
    Subtraction(iValue1,iValue2);
    Multiplication(iValue1,iValue2);
    Division(iValue1,iValue2);

    return 0;
}