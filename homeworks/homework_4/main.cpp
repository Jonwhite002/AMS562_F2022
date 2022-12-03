#include <iostream>
#include "array.hpp"

int main() {

    Array arr1(10,3.2);
    Array arr2(2,1);

    arr1.print();

    std::cout << arr1.norm() << std::endl;
    std::cout << arr1.sum() << std::endl;

    return 0;
}