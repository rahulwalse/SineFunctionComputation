/*
    Implementation of function to calculate exponential growth constant e. where e = 1/0! + 1/1! + 1/2! + ...
*/

#include <iostream>
#include "basicmath.h"
using namespace std;

int ExponentialGrowth(int terms)
{
    float sum = 0;
    /*If the value of term (n) is zero, value of e cannot be calculated.*/    
    if (terms == 0)
    {
        cout << "\nCannot calculate the exponential growth constant e for n=" << terms;
    }
    else
    {
        for (int iteration = 0; iteration < terms; iteration++)
        {
            /*Calculate 1 divided by factorial of current value of iteration and add to sum.*/
            sum = sum + (1 / Factorial(iteration));
        }
        cout << "\nThe exponential growth constant e for n=" << terms << " is " << sum << endl;
    }
    return 0;
}