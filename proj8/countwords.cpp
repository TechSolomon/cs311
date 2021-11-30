// countwords.cpp
// Benjamin Stream
// Solomon Himelbloom
// 2021-11-21
// Source for Exercise A — Program: Counting Words.

#include <iostream> // For std::cerr
#include <map> // For std::map
#include <fstream> // For std::ifstream

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause() {
    std::cout.flush();
    while (std::cin.get() != '\n');
}

// Main program
// Prompt for ENTER before exiting.
// Preconditions: None.
// No-Throw Guarantee Guarantee
int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    int index = 1;

    std::string file;

    std::cout << "Enter your file name (followed by an ENTER): ";
    std::getline(std::cin, file);
    std::ifstream infile(file);

    std::string data;
    std::map<std::string, int> statistic;

    if (infile.fail()) {
        std::cerr << "ERROR: Could not find file!" << std::endl;
    }

    while (infile >> data) {
        if (infile) {
            if (statistic.count(data) == 0) {
                statistic[data] = index;
            } else {
                statistic[data]++;
            }
        }

        // Check for an error on the last operation.
        else if (infile.eof()) {
            break;
        }
    }

    std::cout << "Number of distinct words: " << statistic.size() << std::endl;

    std::cout << std::endl;

    // Output Statistics
    for (const auto& pair : statistic) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << std::endl;

    // Wait for user
    std::cout << "Press ENTER to quit ";
    std::cout << std::endl;
    userPause();
}
