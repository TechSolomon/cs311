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
// For std::max
#include <utility>

// *********************************************************************
// class FSTArray - Class definition
// *********************************************************************


// FIXME:
// class FSTArray
// Frightfully Smart Array of int.
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
    FSTArray(const FSTArray & other);

    // Move ctor
    // No-Throw Guarantee
    FSTArray(FSTArray && other) noexcept;

    // Copy assignment operator
    // TODO: ??? Guarantee
    FSTArray & operator=(const FSTArray & other);

    // Move assignment operator
    // No-Throw Guarantee
    FSTArray & operator=(FSTArray && other) noexcept;

    // Dctor
    // No-Throw Guarantee
    ~FSTArray()
    {
        delete [] _data;
    }

// ***** FSTArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    // TODO:    ???
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }

// ***** FSTArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    [[nodiscard]] size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    [[nodiscard]] bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    [[nodiscard]] const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    [[nodiscard]] const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // TODO: ??? Guarantee
    void resize(size_type newsize);

    // insert
    // TODO: ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item);

    // erase
    // TODO: ??? Guarantee
    iterator erase(iterator pos);

    // push_back
    // TODO: ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // TODO: ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
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
                                    : new value_type[other._capacity])
{
    try {
        std::copy(other.begin(), other.end(), begin());
    }
    catch (...) {
        delete [] _data;
        throw;
    }
    // FIXME: The above call to std::copy does not throw, since it copies int
    //  values. But if value_type is changed, then the call may throw, in
    //  which case this copy ctor may need to be rewritten.
}


// Move ctor
// See header for info.
template <typename F>
FSTArray<F>::FSTArray(FSTArray<F> && other) noexcept
        :_capacity(other._capacity),
         _size(other._size),
         _data(other._data)
{
    other._capacity = 0;
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
template <typename F>
FSTArray<F> & FSTArray<F>::operator=(const FSTArray<F> & other)
{
    FSTArray<F> copy_of_other(other);
    swap(copy_of_other);
    return *this;
}


// Move assignment operator
// See header for info.
template <typename F>
FSTArray<F> & FSTArray<F>::operator=(FSTArray<F> && other) noexcept
{
    swap(other);
    return *this;
}


// resize
// See header for info.
template <typename F>
void FSTArray<F>::resize(FSTArray<F>::size_type newsize)
{
    // if newsize =< capacity set _size to newsize 
    if (newsize <= _capacity) {
        _size = newsize;
    }
    //newSize = newsize, newData using std:copy (cleanup) newCapacity = 2 * capacity, if not allowed then set to newSize.
    else
    {
        // if FSTArray<F> dummy(capacity*2); //?
        // else FSTArray<F> dummy(newsize); //?
        FSTArray<F> dummy(newsize);// Dummy Object to hold data with _size set to newsize;

           // Not sure if this is right, I cant think of another way to handle a badalloc from allocating new memory. 
            try {
                dummy._capacity = size_type(2 * this->_capacity);
            }
            catch (const std::bad_alloc) {
                delete[]  dummy._data;
                dummy._capacity = newsize;
                throw;
            }

        //copies Data over from current object
        try {
            std::copy(this->begin(), this->end(), dummy.begin());
        }
        catch (...) {
          delete[]  dummy._data;
            throw;
        }

        // after data is copied into dummy function, swap dummy obj with current obj
        this->swap(dummy);
        //Dummy should deconstruct after going out of scope....
    }


}


// insert
// See header for info.
template <typename F>
typename FSTArray<F>::iterator FSTArray<F>::insert(FSTArray<F>::iterator pos,
                                                   const FSTArray<F>::value_type & item)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// erase
// See header for info.
template <typename F>
typename FSTArray<F>::iterator FSTArray<F>::erase(FSTArray<F>::iterator pos)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// swap
// See header for info.
template <typename F>
void FSTArray<F>::swap(FSTArray<F> & other) noexcept
{
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(_data, other._data);
}

// End class FSTArray

#endif //PROJ5_FSTARRAY_H
