// countwords.cpp
// Benjamin Stream
// Solomon Himelbloom
// 2021-11-21
// Source for Exercise A — Program: Counting Words.

#include <iostream>

// TODO: Store results (before printing) in an appropriate STL container.

void count() {
    std::cout << "Hello, Counting Words." << std::endl;
}

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause() {
    std::cout.flush();
    while (std::cin.get() != '\n');
}

int main() {
    count();

    // FIXME: Edge cases to avoid all crashes:
    //  - For example, what if the user, when prompted for a filename, just hits ENTER?
    //  - What if they type a bunch of blanks and then hit ENTER?
    //  - What about a filename with a blank in the middle?
    //  - What about the name of a file that does not exist?
    //  - A file that exists but cannot be read?
    //  - An empty file?
    //  - An executable file? a directory?
    //  - Etc.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();
}
