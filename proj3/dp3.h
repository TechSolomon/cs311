// dp3.h
// Solomon Himelbloom
// Glenn G. Chappell
// 2021-09-16
//
// For CS 311 Fall 2021
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <algorithm>   // For std::sort & std::unique

// ValueType
// - Given ptr to Linked List, return its size (number of nodes).
// Pre:
// - Head is nullptr for empty Linked List,
// - [OR] ptr to nullptr-terminated Linked List.
// Requirements on Types:
// - copy ctor & (non-throwing) dctor.
// Invariants: None.
// Exceptions: throws `out_of_range` when exceeding LLNode size.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head, std::size_t index) {
    const LLNode<ValueType> * pointer = head; // Iterates through the list
    std::size_t counter = 0; // Number of nodes thus far

    while (pointer != nullptr) {
        if (counter == index) {
            return pointer->_data;
        }

        pointer = pointer->_next;
        ++counter;
    }

    throw std::out_of_range("ValueType index is out of range!");
}

// Implementation in source file
void didItThrow(const std::function<void()> & ff, bool & threw);

// uniqueCount
// Pre:
// - Takes iterators as parameters.
// Post:
// - Returns number of unique values in the given range.
// Requirements on Types:
// - RAIter is a random-access iterator type.
// Invariants: None.
// Exceptions: None.
template <typename RAIter>
std::size_t uniqueCount(RAIter first, RAIter last) {
    assert(std::distance(first, last) >= 0);

    // Default constructor
    RAIter();

    // OPTIONAL:
    // - Six comparison operators (==, !=, <, <=, >, >=)
    // - The Big Five

    RAIter initial = first;
    RAIter subsequent = std::next(initial, 1);
    assert(std::distance(initial, subsequent) >= -1);

    std::sort(first, last);
    auto wraparound = std::unique(first, last);
    return std::distance(first, wraparound);
}

// Implementation in source file
int gcd(int a, int b);

#endif  //#ifndef FILE_DP3_H_INCLUDED
