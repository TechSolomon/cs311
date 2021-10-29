// fstarray.h
// Solomon Himelbloom
// Benjamin Stream
// 2021-10-21
// Class template for Project 5 (Frightfully Smart Templated Array Class).

#ifndef PROJ5_FSTARRAY_H
#define PROJ5_FSTARRAY_H

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max, std::copy, std::rotate, std::swap

// *********************************************************************
// class FSTArray - Class definition
// *********************************************************************


// class FSTArray
// Frightfully Smart Template Array
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
template <typename F>
class FSTArray {

// ***** FSTArray: types *****
public:

    // value_type: type of data items
    using value_type = F;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** FSTArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 16 };

// ***** FSTArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit FSTArray(size_type size=0)
            :_capacity(std::max(size, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
             _size(size),
             _data(_capacity == 0 ? nullptr
                                  : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    // Pre:
    // - Must be of the type FSTArray.
    // Error:
    // - May throw std::bad_alloc or std::terminate.
    FSTArray(const FSTArray & other);

    // Move ctor
    // No-Throw Guarantee
    // Pre:
    // - Must be of the type FSTArray.
    FSTArray(FSTArray && other) noexcept;

    // Copy assignment operator
    // No-Throw Guarantee
    // Pre:
    // - Must be of the type FSTArray.
    FSTArray & operator=(const FSTArray & other);

    // Move assignment operator
    // No-Throw Guarantee
    // Pre:
    // - Must be of the type FSTArray.
    FSTArray & operator=(FSTArray && other) noexcept;

    // Dctor
    // No-Throw Guarantee
    // Pre:
    // - None.
    ~FSTArray() {
        delete [] _data;
    }

// ***** FSTArray: general public operators *****
public:

    // operator[] - non-const & const
    // No-Throw Guarantee
    // Pre:
    // - 0 <= index <= _size - 1.
    value_type & operator[](size_type index) {
        return _data[index];
    }
    const value_type & operator[](size_type index) const {
        return _data[index];
    }

// ***** FSTArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    [[nodiscard]] size_type size() const noexcept {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    [[nodiscard]] bool empty() const noexcept {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept {
        return _data;
    }
    [[nodiscard]] const_iterator begin() const noexcept {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept {
        return begin() + size();
    }
    [[nodiscard]] const_iterator end() const noexcept {
        return begin() + size();
    }

    // resize
    // Basic Guarantee
    // Pre:
    // - newsize >= 0.
    // Error:
    // - May throw std::bad_alloc or std::terminate.
    void resize(size_type newsize);

    // insert
    // Basic Guarantee
    // Pre:
    // - pos must be within bounds of the FSTArray.
    iterator insert(iterator pos,
                    const value_type & item);

    // erase
    // Basic Guarantee
    // Pre:
    // - pos must be within bounds of the FSTArray.
    // - _size >= 1.
    iterator erase(iterator pos);

    // push_back
    // Basic Guarantee
    // Pre:
    // - None.
    void push_back(const value_type & item) {
        insert(end(), item);
    }

    // pop_back
    // Basic Guarantee
    // Pre:
    // - end() >= 1.
    void pop_back() {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    // Pre:
    // - Must be of the type FSTArray.
    void swap(FSTArray & other) noexcept;

// ***** FSTArray: data members *****
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class FSTArray


// *********************************************************************
// class FSTArray - Member function definitions
// *********************************************************************


// Copy ctor
// See header for info.
template <typename F>
FSTArray<F>::FSTArray(const FSTArray<F> & other)
        :_capacity(other._capacity),
         _size(other.size()),
         _data(other._capacity == 0 ? nullptr
                                    : new value_type[other._capacity]) {
    try {
        std::copy(other.begin(), other.end(), begin());
    }
    catch (...) {
        delete [] _data;
        throw;
    }
}


// Move ctor
// See header for info.
template <typename F>
FSTArray<F>::FSTArray(FSTArray<F> && other) noexcept
        :_capacity(other._capacity),
         _size(other._size),
         _data(other._data) {
    other._capacity = 0;
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
template <typename F>
FSTArray<F> & FSTArray<F>::operator=(const FSTArray<F> & other) {
    FSTArray<F> duplicate(other);
    swap(duplicate);
    return *this;
}


// Move assignment operator
// See header for info.
template <typename F>
FSTArray<F> & FSTArray<F>::operator=(FSTArray<F> && other) noexcept {
    swap(other);
    return *this;
}


// resize
// See header for info.
template <typename F>
void FSTArray<F>::resize(FSTArray<F>::size_type newsize) {
    if (newsize <= _capacity) {
        _size = newsize;
    }

    else {
        size_type limit = std::max(_capacity, newsize * 2);
        auto *dummy = new value_type[limit];

        try {
            std::copy(begin(), end(), dummy);
        }
        catch (...) {
            delete [] dummy;
            throw;
        }

        delete [] _data;

        std::swap(_size, newsize);
        std::swap(_capacity, limit);
        std::swap(_data, dummy);
    }
}


// insert
// See header for info.
template <typename F>
typename FSTArray<F>::iterator FSTArray<F>::insert(FSTArray<F>::iterator pos,
                                                   const FSTArray<F>::value_type & item) {
    std::size_t index = pos - begin();
    std::size_t increment = _size + 1;

    if (pos == end()) {
        resize(increment);
        _data[index] = item;
    }

    else {
        _data[_size] = item;
        resize(increment);
        std::rotate(pos, end() - 1, end());
    }

    return index + begin();
}


// erase
// See header for info.
template <typename F>
typename FSTArray<F>::iterator FSTArray<F>::erase(FSTArray<F>::iterator pos) {
    std::size_t decrement = _size - 1;

    std::rotate(pos, pos + 1, end());
    resize(decrement);
    return pos;
}


// swap
// See header for info.
template <typename F>
void FSTArray<F>::swap(FSTArray<F> & other) noexcept {
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(_data, other._data);
}

#endif //PROJ5_FSTARRAY_H
