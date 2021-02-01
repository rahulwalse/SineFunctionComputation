// SineFunctionComputation.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Program to evaluate function sin(x) as defined by infinite series expansion:
    sin(x)  = (x/1!) - (x^3/3!) + (x^5/5!) - (x^7/7!) + ...
    This program also performs supplementary operations and calculations.
*/

#include <iostream>
#include "basicmath.h"
#include "SineCosine.h"
using namespace std;
const int FIRSTOPTION = 1, LASTOPTION = 4;

int main()
{
    float x;    int choice, totalTerms; char cont;

    do
    {
        cout << "\nChoose any of the following options\n1. Evaluate sine function\n2. Summation of factorial numbers, 0! + 1! + 2! + 3! +... and so on";
        cout << "\n3. Compute exponential growth constant e, where e=1/0! + 1/1! + 1/2! + ... \n4. Evaluate cos function\nEnter your choice:";
        cin >> choice;

        if (choice < FIRSTOPTION || choice > LASTOPTION)
        {
            cout << "\nThe choice you entered is invalid, exiting the program..." << endl;
            return 0;
        }
        else
        {
            switch (choice)
            {
            case 1: cout << "\nEnter the value of x to evaluate sin(x) as defined by infinite series expansion:";
                    cout << "\n\tsin(x) = (x / 1!) - (x ^ 3 / 3!) + (x ^ 5 / 5!) - (x ^ 7 / 7!) + ..." << endl;
                    cout << "x="; cin >> x;
                    cout << "\nThe value after evaluating sin(x), where x=" << x << " is " << SineFunction(x) << endl;
                    break;

            case 2: cout << "\nEnter the number of factorial numbers to be summed\ntotal terms to add: ";
                    cin >> totalTerms;
                    FactorialSummation(totalTerms);
                    break;

            case 3: cout << "\nEnter the value of n to compute exponential growth constant e to n, where e=1/0! + 1/1! + 1/2! + ... " << endl;
                    cout << "n=";   cin >> totalTerms;
                    ExponentialGrowth(totalTerms);
                    break;

            case 4: cout << "\nEnter the value of x to evaluate cos(x) as defined by infinite series expansion:";
                    cout << "\n\tcos(x) = 1 - (X ^ 2 / 2!) + (x ^ 4 / 4!) - (x ^ 6 / 6!) + ..." << endl;
                    cout << "x=";   cin >> x;
                    cout << "\nThe value after evaluating cos(x), where x=" << x << " is " << CosineFunction(x) << endl;
                    break;
            }
        }
        /*Option to continue and choose operations again.*/
        cout << "\nDo you want to continue? (Y/N)" << endl;
        cin >> cont;
    } while (cont == 'Y' || cont == 'y');
}