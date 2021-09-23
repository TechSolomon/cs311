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
#include <algorithm>  // For std::sort & std::unique
#include <iostream>

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

    throw std::out_of_range("Index is out of range.");
}

// Implementation in source file
void didItThrow(const std::function<void()> & ff, bool & threw);

template <typename RAIter>
std::size_t uniqueCount(RAIter first, RAIter last) {
    assert(std::distance(first, last) >= 0);

    //  TODO: Require that the type of the values in the range
    //   has any of the six comparison operators (==, !=, <, <=, >, >=),
    //   along with default constructor and the Big Five.

    RAIter initial = first;
    RAIter subsequent = std::next(initial, 1);
    std::sort(first, last);
    auto wraparound = std::unique(first, last);
    return std::distance(first, wraparound);
}

// Implementation in source file
int gcd(int a, int b);

#endif  //#ifndef FILE_DP3_H_INCLUDED
