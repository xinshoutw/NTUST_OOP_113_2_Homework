////////////////////////////////////////////////////////////////////////////////
/// @brief Define a recursive method GCD()
///        to find the greatest common divisor of two positive integers.
///
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int32_t GCD(const int32_t a, const int32_t b) {
    if (b == 0) {
        return a;
    }

    return GCD(b, a % b);
}

int main() {
    int32_t input_a, input_b;
    while (std::cin >> input_a >> input_b) {
        std::cout << GCD(input_a, input_b) << '\n';
    }
}
