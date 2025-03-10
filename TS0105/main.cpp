////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate a sphere volume by input radius.
///        Limit "6" tailing decimals.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>

#define PI 3.14159265358979323846

int main() {
    // input of positive float number
    double input_radius;

    // adjust to 6 tailing decimal
    std::cout << std::setprecision(6) << std::fixed;

    // read until EOF
    while (std::cin >> input_radius) {
        // radius * radius * pi * (4/3)
        std::cout << input_radius * input_radius * input_radius * PI * 4 / 3 << '\n';
    }

    return 0;
}
