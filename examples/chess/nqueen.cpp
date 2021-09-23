// nqueen.cpp
// Glenn G. Chappell
// 2021-09-22
//
// For CS 311 Fall 2021
// Print solutions to the n-Queens problem
// Example of Recursive Backtracking

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cstdlib>
using std::abs;


using BoardType = vector<int>;  // Holds queen locs on a chessboard

// We represent a partial queen placement on a chessboard as a BoardType
// object (board) and an int (n). The int (n) gives the size of the
// chessboard. Thus, n = 8 means an 8 x 8 chessboard. Object board is a
// listing of the queen positions (columns) on 0 or more rows of the
// chessboard (at most n rows). There is at most one queen per row. Its
// position (column) is given by a number from 0 to n-1, inclusive.
//
// For example, a Board holding 1, 3, with n = 4 means a 4 x 4
// chessboard with queens in its first 2 rows. The queen in the row 0
// (1st row) lies in column 1 (the 2nd square), and the queen in row 1
// (2nd row) lies in column 3 (the 4th & last square). This is pictured
// below:
//
// +---+---+---+---+
// |   | Q |   |   |
// +---+---+---+---+
// |   |   |   | Q |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+
// |   |   |   |   |
// +---+---+---+---+

// We print a queen arrangement by printing the position of the queen in
// each column. For example, "1 3 0 2" represents the following
// arrangement of queens on a 4x4 chessboard:
//
// +---+---+---+---+
// |   | Q |   |   |
// +---+---+---+---+
// |   |   |   | Q |
// +---+---+---+---+
// | Q |   |   |   |
// +---+---+---+---+
// |   |   | Q |   |
// +---+---+---+---+


// printBoard
// Given a full solution to the n-Queens Problem, print it, as described
// above.
// Pre:
//     n > 0
//     board.size() == n
//     Each entry of board is in [0, n-1].
//     board, n represent a full solution to the n-Queens Problem (see
//      above).
void printBoard(const BoardType & board,
                int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            cout << " ";
        cout << board[i];
    }
    cout << endl;
}


bool checkQueen(const BoardType & board,
                int n,
                int newcol)
{
    int newrow = static_cast<int>(board.size());
    for (int oldrow = 0; oldrow < newrow; ++oldrow)
    {
        int oldcol = board[oldrow];

        if (oldcol == newcol)
            return false;

        if (abs(newrow-oldrow) == abs(newcol-oldcol))
            return false;
    }
    return true;
}

void nQueen_recurse(BoardType board,
                    int n)
{
    // BASE CASE
    if (static_cast<int>(board.size()) == n)
    {
        printBoard(board, n);
        return;
    }

    // RECURSIVE CASE
    for (int newcol = 0; newcol < n; ++newcol)
    {
        if (checkQueen(board, n, newcol))
        {
            board.push_back(newcol);
            nQueen_recurse(board, n);
            board.pop_back();
        }
    }
}


// nQueen
// Print all solutions to the n-Queens Problem (see above) for a
// chessboard of the given size. That is, print a representation of
// every placement of n mututally non-attacking queens on an n x n
// chessboard.
// Pre:
//     n > 0.
void nQueenCount(int n)
{
    BoardType board;
    nQueen_recurse(board, n);
}


// getInt
// Input an integer. On non-fatal error, print message and retry. On
// fatal error, return false. On successful input, set n to integer that
// was read and return true.
bool getInt(const string & prompt,  // Print this before doing input
            int & n)                // Number we input
{
    // Prompt & input chessboard size, with retry on bad input
    while (true)
    {
        bool founderror = false;
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())      // End of file
                return false;   // Fatal error
            cin.clear();
            cin.ignore();
            founderror = true;  // Bad input; retry
        }
        else
        {
            istringstream is(line);
            is >> n;
            if (!is)
                founderror = true;  // Bad read from string; retry
        }

        if (!founderror)
            break;
        cout << endl;
        cout << "Try again; please type an integer" << endl;
    }

    return true;  // Successful input
}


// Main program
// Repeatedly input a number n and print all n-Queen solutions.
// Terminates on fatal error in input or n <= 0.
int main()
{
    while (true)
    {
        // Print explanation
        cout << "n-Queen Solver" << endl;
        cout << endl;

        // Prompt & get chessboard size
        int n;
        bool good = getInt("Chessboard size (0 to quit?) ", n);
        if (!good || n <= 0)
            break;

        // Print solutions to n-Queens Problem
        cout << endl;
        cout << "n-Queen Solutions for "
             << n << " x " << n << " chessboard:" << endl;
        cout << "-----------------------" << endl;
        nQueen(n);
        cout << "-----------------------" << endl;
        cout << endl;
    }
}

