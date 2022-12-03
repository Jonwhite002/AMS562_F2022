#include <iostream>
#include "array.hpp"

int main() {

    Array arr1(3,3.2);
    Array arr2(4,2.7);

    arr1.print();

    std::cout << arr1.at(4) << std::endl;

    return 0;
}