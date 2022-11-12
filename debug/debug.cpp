#include <cmath>
#include <cstdlib>
#include <iostream>
#include "test.hpp"

//double diff(double h, double (*f)(double)); // Passing function as argument

int main(int argc, char *argv[]) {
    // const double pi_4 = 0.25 * 3.14159265;
    // double h = 0.0;

    //double diff_acos = diff(h, std::acos);

    double a, b;
    a = 2;
    b = 9;

    std::cout << a << " " << b << std::endl;

    swap(a, b);

    std::cout << a << " " << b << std::endl;

    return 0;
}