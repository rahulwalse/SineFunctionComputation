/*
    Method to evaluate sin(x) as defined by infinite series expansion: 
    sin(x) = (x / 1!) - (x ^ 3 / 3!) + (x ^ 5 / 5!) - (x ^ 7 / 7!) + ...
    with error margin of 0.000001 or 1x10^-6.
*/

#include "basicmath.h"
const double error_margin = 0.000001;

float SineFunction(float x)
{
    int next_term;  float term, tsin, x2;
    /*Initial term*/
    term = x;
    tsin = x;
    x2 = x * x;
    next_term = 1;

    /*Consequent terms to evaluate until the value of the term is greater than the error margin.*/
    while (Absolute(term) > error_margin)
    {
        next_term = next_term + 2;
        term = -term * x2 / (next_term * (next_term - 1));
        tsin = tsin + term;
    }
    return tsin;
}