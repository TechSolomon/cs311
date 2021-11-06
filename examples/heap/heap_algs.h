// heap_algs.h
// Glenn G. Chappell
// 2021-11-05
//
// For CS 311 Fall 2021
// Header for Heap Algorithms
// There is no associated source file.

#ifndef FILE_HEAP_ALGS_H_INCLUDED
#define FILE_HEAP_ALGS_H_INCLUDED

#include <cassert>
// For assert
#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::swap

// heapTest
// Determines whether given random-access range is a Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <.
// Pre:
//     [first, last) is a valid range.
// Exception neutral. Throws what & when a value-type operation throws.
// Strong guarantee.
// If operator< does not throw, then No-Throw Guarantee.
template<typename RAIter>
bool heapTest(RAIter first, RAIter last)
{
    assert(last != first);
    std::size_t curr = (last - first) - 1; // Index of item to sift-up
    while (curr != 0) // While current item is not the root
    {
        std::size_t parent = (curr - 1) / 2; // Index of parent
        if (!first[parent] < first[curr]) // C++20 Note: <=> (spaceship operator) 🚀
            break; // No more sifting; done

        // Sift up one level
        std::swap(first[curr], first[parent]);
        curr = parent;
    }
}


// heapInsert
// Heap insert operation on a random-access range.
// Inserts *(last-1) into Heap [first, last-1).
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last-1) forms a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapInsert(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapDelete
// Heap delete operation on a random-access range.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid nonempty range.
//     [first, last) forms a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapDelete(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapMake
// Turns the given random-access range into a Heap using a linear number
// of compare & swap operations.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapMake(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


// heapToSorted
// Given a Heap, sorts it by "<", ascending. Not stable.
// Sorts the given Heap.
// Requirements on Types:
//     RAIter is a random-access iterator type.
//     The value type of RAIter must have <, copy ctor, copy =.
// Pre:
//     [first, last) is a valid range.
//     [first, last) is a Heap.
// Exception neutral. Throws what & when a value-type operation throws.
// Basic guarantee.
// If operator< and swap do not throw, then No-Throw Guarantee.
template<typename RAIter>
void heapToSorted(RAIter first, RAIter last)
{
    // TODO: WRITE THIS!!!
}


#endif //#ifndef FILE_HEAP_ALGS_H_INCLUDED

