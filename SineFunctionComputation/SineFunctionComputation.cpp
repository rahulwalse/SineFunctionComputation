// SineFunctionComputation.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Program to evaluate function sin(x) as defined by infinite series expansion:
    sin(x)  = (x/1!) - (x^3/3!) + (x^5/5!) - (x^7/7!) + ...
    This program also performs supplementary operations and calculations.
*/

#include <iostream>
#include "basicmathf.h"

using namespace std;
const int FIRSTOPTION = 1, LASTOPTION = 4;
const double error_margin = 0.000001;

float EvaluateSineFunction(float x);
int FactorialSummation(int terms);
int ExponentialGrowth(int terms);
float EvaluateCosineFunction(float x);


int main()
{
    float x;    int choice, total_terms;

    cout << "\nChoose any of the following options\n1. Evaluate sine function\n2. Summation of factorial numbers, 0! + 1! + 2! + 3! +... and so on\n3. Compute exponential growth";
    cout << " constant e, where e=1/0! + 1/1! + 1/2! + ... \n4. Evaluate cos function\nEnter your choice:";
    cin >> choice;

    if (choice < FIRSTOPTION or choice > LASTOPTION)
    {
        cout << "\nThe choice you entered is invalid, exiting the program..." << endl;
        return 0;
    }
    else
    {
        switch (choice)
        {
        case 1: cout << "\nEnter the value of x to evaluate sin(x) as defined by infinite series expansion:\n\tsin(x) = (x / 1!) - (x ^ 3 / 3!) + (x ^ 5 / 5!) - (x ^ 7 / 7!) + ..." << endl;
            cout << "x="; cin >> x;
            cout << "\nThe value after evaluating sin(x), where x=" << x << " is " << EvaluateSineFunction(x) << endl;
            break;

        case 2: cout << "\nEnter the number of factorial numbers to be summed\ntotal terms to add: ";
            cin >> total_terms;
            FactorialSummation(total_terms);
            break;

        case 3: cout << "\nEnter the value of n to compute exponential growth constant e to n, where e=1/0! + 1/1! + 1/2! + ... " << endl;
            cout << "n=";   cin >> total_terms;
            ExponentialGrowth(total_terms);
            break;

        case 4: cout << "\nEnter the value of x to evaluate cos(x) as defined by infinite series expansion:\n\tcos(x) = 1 - (X^2/2!) + (x^4/4!) - (x^6/6!) + ..." << endl;
            cout << "x=";   cin >> x;
            cout << "\nThe value after evaluating cos(x), where x=" << x << " is " << EvaluateCosineFunction(x) << endl;
            break;
        }
    }
}

/*
    Method to evaluate sin(x) as defined by infinite series expansion: sin(x) = (x / 1!) - (x ^ 3 / 3!) + (x ^ 5 / 5!) - (x ^ 7 / 7!) + ...
    with error margin of 0.000001 or 1x10^-6.
*/
float EvaluateSineFunction(float x)
{
    int next_term;  float term, tsin, x2;

    //Initial term
    term = x;
    tsin = x;
    x2 = x * x;
    next_term = 1;

    //Consequent terms to evaluate
    while (AbsoluteNumber(term) > error_margin)
    {
        next_term = next_term + 2;
        term = -term * x2 / (next_term * (next_term - 1));
        tsin = tsin + term;
    }
    return tsin;
}

//Implementation to calculate sum of factorial numbers for terms provided by the user.
int FactorialSummation(int terms)
{
    int sum = 0;
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


//Implementation to calculate exponential growth constant e. where e = 1/0! + 1/1! + 1/2! + ...
int ExponentialGrowth(int terms)
{
    float sum = 0;

    if (terms == 0)   //If the value of term (n) is zero, value of e cannot be calculated.
    {
        cout << "\nCannot calculate the exponential growth constant e for n=" << terms;
    }
    else
    {
        for (int iteration = 0; iteration < terms; iteration++)
        {
            sum = sum + (1 / Factorial(iteration)); //Calculate 1 divided by factorial of current value of iteration and add to sum.
        }
        cout << "\nThe exponential growth constant e for n=" << terms << " is " << sum << endl;
    }
    return 0;
}

/*
    Method to evaluate cos(x) as defined by infinite series expansion: cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + (x^8 / 8!) + ...
    with error margin of 0.000001 or 1x10^-6.
*/
float EvaluateCosineFunction(float x)
{
    int next_term;  float term, x2, tcos;

    //Initial term.
    tcos = x;
    term = x;
    x2 = x * x;
    next_term = 0;

    //Keep generating the next terms until the value of the term is greater than the error margin.
    while (AbsoluteNumber(term) > error_margin)
    {
        next_term = next_term + 2;
        term = -term * x2 / (next_term * (next_term - 1));
        tcos = tcos + term;
    }
    return tcos;
}