//
// Created by Solomon on 9/3/21.
//

#ifndef INTARRAY_INTARRAY_H
#define INTARRAY_INTARRAY_H

#include <cstddef>

class IntArray {
public:
    using size_type = std::size_t;
    using value_type = int;

public:
    IntArray(size_type size) :_theArray(new value_type[size]){
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

public:
    // TODO: Pointers can (mostly) be uses as arrays. In particular, add the bracket operator.
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
