/*
    Implementation of function to evaluate cos(x) as defined by infinite series expansion: 
    cos(x) = 1 - (x^2 / 2!) + (x^4 / 4!) - (x^6 / 6!) + (x^8 / 8!) + ...
    with error margin of 0.000001 or 1x10^-6.
*/

#include "basicmath.h"
const double error_margin = 0.000001;

float CosineFunction(float x)
{
    int next_term;  float term, x2, tcos;
    /*Initial term.*/
    tcos = x;
    term = x;
    x2 = x * x;
    next_term = 0;

    /*Consequent terms to evaluate until the value of the term is greater than the error margin.*/
    while (Absolute(term) > error_margin)
    {
        next_term = next_term + 2;
        term = -term * x2 / (next_term * (next_term - 1));
        tcos = tcos + term;
    }
    return tcos;
}