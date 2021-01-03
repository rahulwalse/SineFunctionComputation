//Header file to calculate basic maths functions like absolute of a number or factorial of number etc.

#pragma once

//Function to return the absolute value of given number.
float AbsoluteNumber(float number)
{
    if (number < 0)   //If number is negative number then make it positive.
    {
        return -number;
    }
    else
    {
        return number;
    }
}

//Method for calculating factorial of given number.
float Factorial(int number)
{
    int factorial = 1;
    if (number == 0)
    {
        return factorial;
    }
    else
    {
        for (int iteration = number; iteration >= 1; iteration--)
        {
            factorial = factorial * iteration;
        }
        return factorial;
    }
}

//Mehod to calculate x raise to y (x^y) for given value of x and y.
float Exponent(int base, int exponent)
{
    float baseraisetoexponent;
    baseraisetoexponent = base;

    if (exponent < 0)   //If the exponent is negative, make it positive and calculate 1/x^n.
    {
        exponent = -exponent;
        baseraisetoexponent = 1 / Exponent(base, exponent);
        return baseraisetoexponent;
    }
    else if (exponent == 0)   //If the exponent is 0, then the value will always be 1, as x^0=1.
    {
        return 1;
    }
    else
    {
        for (int iteration = 1; iteration < exponent; iteration++)
        {
            baseraisetoexponent = baseraisetoexponent * base;
        }
        return baseraisetoexponent;
    }
}