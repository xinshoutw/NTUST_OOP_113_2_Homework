/*
Given an arbitrary integer INPUT ( INPUT ), follow the requirements below to output it:
If the number of characters in INPUT (including the negative sign) is less than 10 digits, fill in the space at the beginning, so that the number of spaces plus the number of characters in INPUT just meets 10 digits.

Each line represents an INPUT, the program continues to request input, and ends if EOF is read.

Each line is output according to the requirements of the problem.

5
2147483647
12345678901234567890

5
2147483647
12345678901234567890
 */

#include <iomanip>
#include <iostream>

int main() {
    // Because the input number is greater than INT64_MAX
    // Store input in a char array

    char input[20];
    while (std::cin >> input) {
        std::cout << std::setw(10) << input << std::endl;
    }

    return 0;
}
