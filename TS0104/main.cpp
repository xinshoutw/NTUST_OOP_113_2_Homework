////////////////////////////////////////////////////////////////////////////////
/// @brief Print numbers with minimal width limit.
///        Add padding space to beginning to match at least 10 characters.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>

int main() {
    // store in a char array because of unlimited input number size
    char input_number[20];

    // adjust to 10 minimal width
    std::cout << std::setw(10);
    while (std::cin >> input_number) {
        std::cout << input_number << '\n';
    }

    return 0;
}
