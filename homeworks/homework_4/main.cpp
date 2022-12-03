#include <iostream>
#include "array.hpp"

int main() {

    Array arr1(3,3.2);
    Array arr2(4,2.7);

    arr1.at(0) = 2.4;
    arr1.at(1) = -9.2;
    arr1.at(2) = 5.9;

    Array arr3 = arr1.add(arr2);

    arr3.print();

    return 0;
}