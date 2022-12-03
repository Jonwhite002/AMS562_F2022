#include <iostream>
#include "array.hpp"

int main() {

    Array arr1(4,3.2);
    Array arr2(4,2.7);

    arr1[0] = 2.4;
    arr1[1] = -9.2;
    arr1[2] = 5.9;

    Array arr3 = arr1 + arr2;

    arr3.print();

    return 0;
}