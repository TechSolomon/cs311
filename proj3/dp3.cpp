// dp3.cpp
// Solomon Himelbloom
// Glenn G. Chappell
// 2021-09-16
//
// For CS 311 Fall 2021
// Source for Project 3 functions

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;

// didItThrow
// Pre: None.
// Requirements on Types:
// - function pointer & threw as bool
// - [OR] an object which has operator() defined
// Invariants: None.
// Exceptions: Catch All & Re-Throw.
void didItThrow(const function<void()> & ff, bool & threw) {
    try {
        ff();
        threw = false;
    } catch (...) {
        threw = true;
        throw;
    }
}

// gcd (greatest common divisor)
// - The greatest integer that divides evenly.
// Pre:
// - a && b >= 0
// - a || b == 0 (not both)
// Requirements on Types:
// - gcd is the value of type int.
// Exceptions: None.
int gcd(int a, int b) {
    // BASE CASE
    if (a > b) {
        return gcd(b, a);
    }

    else if (a == 0) {
        return b;
    }

    // RECURSIVE CASE
    // Invariant: a && b >= 0
    return gcd(b % a, a);
}
