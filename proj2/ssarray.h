// ssarray.h
// Solomon Himelbloom
// 2021-09-10
// Header for class template SSArray.

#ifndef PROJ2_SSARRAY_H
#define PROJ2_SSARRAY_H

#include <cstddef>  // For std::size_t
#include <algorithm> // For std::copy & std::swap

// Requirements on Types: ValType
template<typename ValType>
class SSArray {
// SSArray Member Types
public:
    using value_type = ValType;
    using size_type = std::size_t;

public:
    // Default Ctor
    SSArray()
    : _arrayPtr(new value_type[8]), _sizePtr(8) {

    }

    // Ctor from size
    // Not an implicit type conversion.
    // Parameter size must be non-negative.
    explicit SSArray(size_type size) {
        _arrayPtr = new value_type[size];
        _sizePtr = size;
    }

    SSArray(value_type valueType, size_type size)
    :_arrayPtr(new value_type[size]), _sizePtr(size) {
        std::fill(begin(), end(), valueType);
    }

    // Dctor
    ~SSArray() {
        delete [] _arrayPtr;
    }

    // Copy ctor
    SSArray(const SSArray & other)
    : _arrayPtr(new value_type[_sizePtr]), _sizePtr(other.size()) {
        std::copy(other.begin(), other.end(), begin());
    }

    // Move ctor
    SSArray(SSArray && other) noexcept
    : _arrayPtr(other._arrayPtr), _sizePtr(other.size()) {
        other._arrayPtr = nullptr;
    }

    // Copy assignment
    SSArray & operator=(const SSArray & other) {
        SSArray copy(other);
        reverse(copy);
        return *this;
    }

    // Move assignment
    SSArray & operator=(SSArray && other) noexcept {
        reverse(other);
        return *this;
    }

// SSArray: General (public) member functions
public:
    // size (return: size of array)
    [[nodiscard]] size_type size() const {
        return _sizePtr;
    }

    // begin (return: ptr to first item in array)
    value_type *begin() {
        return _arrayPtr;
    }

    const value_type *begin() const {
        return _arrayPtr;
    }

    // end (return: ptr to one past last item in array)
    value_type *end() {
        return begin() + size();
    }

    const value_type *end()  const {
        return begin() + size();
    }

// SSArray: General (public) operators
public:

    //  op[] - non-const & const
    //  Parameter index must be in the range [1, size), where size is the
    //  parameter passed to the ctor.
    value_type & operator[](size_type size) {
        return _arrayPtr[size];
    }

    const value_type & operator[](size_type size) const {
        return _arrayPtr[size];
    }

// SSArray: Data members & member functions
private:
    ValType *_arrayPtr;
    size_t _sizePtr{};

    // No exceptions thrown.
    void reverse(SSArray & other) noexcept {
        std::swap(_sizePtr, other._sizePtr);
        std::swap(_arrayPtr, other._arrayPtr);
    }
};

// Equality operator comparison
template <typename ValType>
bool operator==(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return (lhs.size() == rhs.size());
}

// Inequality operator comparison
template <typename ValType>
bool operator!=(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return !(lhs.size() == rhs.size());
}

// Less than comparison
template <typename ValType>
bool operator<(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return lhs.size() < rhs.size();
}

// Less than or equal to comparison
template <typename ValType>
bool operator<=(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return lhs == rhs || lhs < rhs;
}

// Greater than comparison
template <typename ValType>
bool operator>(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return lhs > rhs;
}

// Greater than or equal to comparison
template <typename ValType>
bool operator>=(const SSArray<ValType> & lhs, const SSArray<ValType> & rhs) {
    return lhs == rhs || lhs > rhs;
}

#endif //PROJ2_SSARRAY_H
