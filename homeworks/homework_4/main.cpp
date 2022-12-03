#include <iostream>
#include "array.hpp"

int main() {

    Array arr1(5);
    Array arr2(6, 1);
    Array arr3;

    arr1.print();

    arr1[0] = 2.4; arr1[1] = -9.2; arr1[2] = 5.9;

    arr3.print();

    return 0;
}