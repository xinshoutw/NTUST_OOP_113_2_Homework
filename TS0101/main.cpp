////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate the square root of a positive number by Babylonian algorithm.
///        Limit "2" tailing decimals.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>

int main() {
    // input of positive number
    double input_number;

    // adjust to 2 tailing decimal
    std::cout << std::setprecision(2) << std::fixed;

    // read until EOF
    while (std::cin >> input_number) {
        double guess = input_number / 2;
        double approximate_guess;

        // loop until guess ~ approximate_guess
        do {
            approximate_guess = input_number / guess;
            guess = (guess + approximate_guess) / 2;
        } while (guess - approximate_guess >= 0.01);

        std::cout << guess << '\n';
    }

    return 0;
}
