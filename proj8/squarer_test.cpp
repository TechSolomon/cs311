// squarer_test.cpp
// Benjamin Stream
// Solomon Himelbloom
// Glenn G. Chappell
// 2021-11-19
//
// For CS 311 Fall 2021
// Test program for class Squarer
// For Project 8, Exercise B
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, squarer.h

// Includes for code to be tested
#include "squarer.h"         // For class Squarer
#include "squarer.h"         // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
// NONE

// Printable name for this test suite
const std::string test_suite_name =
    "class Squarer"
    " - CS 311 Proj 8, Ex B";


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("Squarer: Positive Ints")
{
    Squarer sq;
    for (int range = 2; range < 100; ++range)
    {
        int result = range * range;
        SUBCASE("Square " + range);
        INFO(range <<" squared is " << result);
        REQUIRE(sq(range) == result);
    }
}

TEST_CASE("Squarer: Negative Ints")
{
    Squarer sq;
    for (int range = -2; range > -100; --range)
    {
        int result = range * range;
        SUBCASE("Square " + range);
        INFO(range << " squared is " << result);
        REQUIRE(sq(range) == result);
    }
}

TEST_CASE("Squarer: Wide Positive Ints")
{
    //int value ~46340^2 is max int value
    Squarer sq;
    for (int range = 2; range < 46340; range+= 300)
    {
        int result = range * range;
        SUBCASE("Square " + range);
        INFO(range << " squared is " << result);
        REQUIRE(sq(range) == result);
    }
}

TEST_CASE("Squarer: Wide Negative Ints")
{
    //int value ~46340^2 is max int value
    Squarer sq;
    for (int range = -2; range > -46340; range -= 300)
    {
        int result = range * range;
        SUBCASE("Square " + range);
        INFO(range << " squared is " << result);
        REQUIRE(sq(range) == result);
    }
}

TEST_CASE("Squarer: Positive Floats")
{
    Squarer sq;

        float test = 1.1;
        float result = 1.21;
        SUBCASE("Square Positive Floats 1.1");
        INFO(result << " squared is " << test);
        REQUIRE(sq(test) == doctest::Approx(result));
}

TEST_CASE("Squarer: Negative Floats")
{
    Squarer sq;

    float test = -1.1;
    float result = 1.21;
    SUBCASE("Square Negative Floats -1.1");
    INFO(result << " squared is " << test);
    REQUIRE(sq(test) == doctest::Approx(result));
}

TEST_CASE("Squarer: Wide Negative Floats")
{
    Squarer sq;

    float test = -13452.32;
    float result = 180964913.382;
    SUBCASE("Square Wide Negative Floats -13452.32");
    INFO(result << " squared is " << test);
    REQUIRE(sq(test) == doctest::Approx(result));
}

TEST_CASE("Squarer: Wide Positive Floats")
{
    Squarer sq;

    float test = 13452.32;
    float result = 180964913.382;
    SUBCASE("Square Wide Positive Floats 13452.32");
    INFO(result << " squared is " << test);
    REQUIRE(sq(test) == doctest::Approx(result));
}

TEST_CASE("Squarer: Special Cases  -1, 0, 1")
{
    Squarer sq;

    for (int square = 1; square != -1; --square)
    {
           int result = square * square;
           SUBCASE("Special Ints Squares");
           INFO(square << " squared is " << result);
           REQUIRE(sq(square) == result);
    }

    for (float square = 1; square != -1; --square)
    {
        float result = square * square;
        SUBCASE("Special Float Squares");
        INFO(square << " squared is " << result);
        REQUIRE(sq(square) == result);
    }

}

//TODO
TEST_CASE("Squarer: Const?") {
   const Squarer sq;
   int test = 3;
   int result = 9;
   SUBCASE("Const Squarer");
   INFO(test << " squared is " << result);
   REQUIRE(sq(test) == result);
}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

