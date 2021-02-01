/*
    Function implementation to calculate sum of factorial numbers for terms provided by the user.
*/

#include <iostream>
#include "basicmath.h"
using namespace std;

int FactorialSummation(int terms)
{
    int sum = 0;
    /*Check that the terms are greater than 0*/
    if (terms == 0)
    {
        cout << "\nCannot sum the factorial number for term= " << terms;
    }
    else
    {
        for (int iteration = 0; iteration < terms; iteration++)
        {
            sum = sum + Factorial(iteration);
        }
        cout << "\nThe summation of factorial numbers for first " << terms << " terms is " << sum << endl;
    }
    return 0;
}