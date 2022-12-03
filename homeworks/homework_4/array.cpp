#include <iostream>
#include <cmath>
#include "array.hpp"

// default constructor
Array::Array() {
    _size = 0;
    _data = 0;
}

// copy constructor
Array::Array(const Array &other) {
    _size = other._size;
    for(int i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

// constructor with array size & values
Array::Array(unsigned n, double v) {
    _size = n;
    _data = new double [n];
    for (int i = 0; i < n; ++i) {
        _data[i] = v;
    }
}

// destructor
Array::~Array() {
    delete[] _data;
}

// get length of array
unsigned Array::size() const {return _size;}

// copy
void Array::copy(const Array &rhs) {
    if (_size != rhs._size) {
        std::cerr << "ERROR: Left and right hand sides are not of same size\n";
        return;
    }
    for(int i = 0; i < _size; ++i) {
        _data[i] = rhs._data[i];
    }
}

// terminal printing
void Array::print() const {
    std::cout << "Size: " << _size << "\nElements: [ ";
    for (int i = 0; i < _size; ++i) {
        std::cout << _data[i] << " ";
    }std::cout << "]" << std::endl;
}

// math functions
double Array::norm() const {
    double temp = 0;
    for (int i = 0; i < _size; ++i) {
        temp = temp + pow(_data[i],2);
    } 
    return(sqrt(temp));
}

double Array::sum() const {
    double temp = 0;
    for (int i = 0; i < _size; ++i) {
        temp = temp + _data[i];
    } 
    return(temp);
}