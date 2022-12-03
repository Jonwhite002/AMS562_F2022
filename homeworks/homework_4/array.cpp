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

unsigned Array::size() const {return _size;}

double *Array::data() {return _data;}

const double *Array::data() const {return _data;}

double &Array::at(unsigned index) {
    if (index >= _size) {
        std::cerr << "Error: Index exceeds number of array elements. Index must not exceed "
        << _size-1 << std::endl;
        return _data[0]; // CHANGE ME
    }
    return _data[index];
}

const double &Array::at(unsigned index) const {
    if (index >= _size) {
        std::cerr << "Error: Index exceeds number of array elements. Index must not exceed "
        << _size-1 << std::endl;
        return _data[0]; // CHANGE ME
    }
    return _data[index];
}

void Array::copy(const Array &rhs) {
    if (_size != rhs._size) {
        std::cerr << "ERROR: Left and right hand sides are not of same size\n";
        return;
    }
    for(int i = 0; i < _size; ++i) {
        _data[i] = rhs._data[i];
    }
}


void Array::print() const {
    std::cout << "Size: " << _size << "\nElements: [ ";
    for (int i = 0; i < _size; ++i) {
        std::cout << _data[i] << " ";
    }std::cout << "]" << std::endl;
}


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

double Array::dot(const Array &rhs) const {
    if (_size != rhs._size) {
        std::cerr << "ERROR: Left and right hand sides are not of same size\n";
        return -1;
    }
    double temp = 0;
    for (int i = 0; i < _size; ++i) {
        temp = temp + _data[i]*rhs._data[i];
    } 
    return(temp);
}

Array Array::add(const Array &rhs) const {
    for (int i = 0; i < _size; ++i) {
        this->_data[i] = _data[i]+rhs._data[i];
    }
}