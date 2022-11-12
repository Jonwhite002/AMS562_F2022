#include <iostream>

void swap(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
}