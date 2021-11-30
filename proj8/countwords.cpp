// countwords.cpp
// Benjamin Stream
// Solomon Himelbloom
// 2021-11-21
// Source for Exercise A — Program: Counting Words.

#include <iostream>
#include <iomanip>
#include <map> // For std::map
#include <string>
#include <fstream>
#include <sstream>

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause() {
    std::cout.flush();
    while (std::cin.get() != '\n');
}

// FIXME: Edge cases to avoid all crashes:
//  - For example, what if the user, when prompted for a filename, just hits ENTER?
//  - What if they type a bunch of blanks and then hit ENTER?
//  - What about a filename with a blank in the middle?
//  - What about the name of a file that does not exist?
//  - A file that exists but cannot be read?
//  - An empty file?
//  - An executable file? a directory?

// Main program
// Prompt for ENTER before exiting.
int main(int argc, char *argv[]) {
    int index = 0;

    std::string file;

    std::cout << "Enter your file name (followed by an ENTER): ";
    std::getline(std::cin, file);
    std::ifstream infile(file);

    std::string stat;
    std::map<std::string, int> statistics;

    if (infile.fail()) {
        std::cerr << "ERROR: Could not find file!" << std::endl;
    }

    while (infile >> stat) {
        if (!infile) {
            if (statistics.count(stat) == 0) {
                // DUMMY
            }
            else {
                // DUMMY
            }
        }

        // Check for an error on the last operation.
        else if (infile.eof()) {
            break;
        }
    }

    // TODO: Output Statistics

    // std::cout << "Number of distinct words: " << index << std::endl;

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();
}
