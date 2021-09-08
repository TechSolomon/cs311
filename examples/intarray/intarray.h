// intarray.h
// Solomon Himelbloom
// 2021-09-03
// Header file for class IntArray.
//
// Final class example: https://github.com/ggchappell/cs311-2021-03/blob/main/intarray.h

#ifndef INTARRAY_INTARRAY_H
#define INTARRAY_INTARRAY_H

#include <cstddef>

class IntArray {
public:
    using size_type = std::size_t;
    using value_type = int;

    explicit IntArray(size_type size) :_theArray(new value_type[size]){
        _theArray = new value_type[size];
    }

    ~IntArray() {
        delete [] _theArray;
    }

    // IntArray() = delete;
    IntArray(const IntArray & other) = delete;
    IntArray & operator=(const IntArray & other) = delete;
    IntArray(IntArray && other) = delete;
    IntArray & operator=(IntArray && other) = delete;

    // Pointers can (mostly) be used as arrays.
    // In particular, add the bracket operator.
    value_type & operator[](size_type index) {
        return _theArray[index];
    }

    const value_type & operator[](size_type index) const {
        return _theArray[index];
    }

private:
    value_type * _theArray;
};

#endif //INTARRAY_INTARRAY_H
