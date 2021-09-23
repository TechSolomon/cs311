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

void didItThrow(const function<void()> & ff, bool & threw) {
    try {
        ff();
        threw = false;
    }
    catch (...) {
        threw = true;
        throw;
    }
}

// greatest common divisor (GCD)
int gcd(int a, int b) {
    // BASE CASE
    if (a > b) {
        return gcd(b, a);
    }

    else if (a == 0) {
        return b;
    }

    // RECURSIVE CASE
    return gcd(b % a, a);
}
