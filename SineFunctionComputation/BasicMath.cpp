/*
    This source file contains functions for calculating some basic math functions like
    absolute of a number, factorial of number and exponent x^y for given values of x & y.
*/

/*Implementation of function to return the absolute value for a given number.*/
float Absolute(float number)
{
    /*If number is negative number then make it positive.*/
    if (number < 0)
    {
        return -number;
    }
    else
    {
        return number;
    }
}

/*Implementation of function for calculating factorial of a given number.*/
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

/*Implementation of function to calculate x raise to y (x^y) for given value of x and y.*/
float Exponent(int base, int exponent)
{
    float baseraisetoexponent;
    baseraisetoexponent = base;
    /*If the exponent is negative, make it positive and calculate 1/x^n.*/
    if (exponent < 0)
    {
        exponent = -exponent;
        baseraisetoexponent = 1 / Exponent(base, exponent);
        return baseraisetoexponent;
    }
    else if (exponent == 0)
    {
        /*If the exponent is 0, then the value will always be 1, as x^0=1.*/
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