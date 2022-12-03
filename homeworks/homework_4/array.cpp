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

void Array::copy(const Array &rhs) {
    if (_size != rhs._size) {
        std::cerr << "ERROR: Left and right hand sides are not of same size\n";
        return;
    }
    for(int i = 0; i < _size; ++i) {
        _data[i] = rhs._data[i];
    }
}

double &Array::at(unsigned index) {return _data[index];}

const double &Array::at(unsigned index) const {return _data[index];}

void Array::resize(unsigned new_size, bool prsv) {
    double * new_data;
    new_data = new double [new_size];

    unsigned size = 0;
    if (prsv) {
        size = std::min(new_size, _size);
        for (int i = 0; i < size; ++i)
            new_data[i] = _data[i];
    }

    for (int i = size; i < new_size; ++i)
        new_data[i] = 0.0;

    delete[] _data;
    _size = new_size;
    _data = new_data;
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

double Array::max() const {
    double temp = 0;
    for (int i = 0; i < _size; ++i) {
        temp = (temp < _data[i]) ? _data[i] : temp;
    }
    return temp;
}

double Array::min() const {
    double temp = 0;
    for (int i = 0; i < _size; ++i) {
        temp = (temp > _data[i]) ? _data[i] : temp;
    }
    return temp;
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
    Array arr(rhs._size);
    for (int i = 0; i < arr._size; ++i) {
        arr._data[i] = _data[i]+rhs._data[i];
    }
    return(arr);
}

Array Array::sub(const Array &rhs) const {
    Array arr(rhs._size);
    for (int i = 0; i < arr._size; ++i) {
        arr._data[i] = _data[i]-rhs._data[i];
    }
    return(arr);
}

void Array::print() const {
    std::cout << "Size: " << _size << "\nElements: [ ";
    for (int i = 0; i < _size; ++i) {
        std::cout << _data[i] << " ";
    }std::cout << "]" << std::endl;
}

double &Array::operator[](const unsigned index) {return _data[index];}
const double &Array::operator[](const unsigned index) const {return _data[index];}

Array &Array::operator=(const Array &other) {
    if (_size != other._size) {
        resize(other._size, false);
    }
    copy(other);
    return *this;
}

Array operator+(const Array &lhs, const Array &rhs) {
    return lhs.add(rhs);
}

Array operator-(const Array &lhs, const Array &rhs) {
    return lhs.sub(rhs);
}