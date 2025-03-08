////////////////////////////////////////////////////////////////////////////////
/// @brief Given a positive number as a time in seconds. Convert and print its hours, minutes and seconds.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main() {
    // input of positive number as a time in seconds
    uint64_t input_seconds;

    // read until EOF
    while (std::cin >> input_seconds) {
        const uint64_t hours = input_seconds / 3600;
        const uint64_t minutes = (input_seconds % 3600) / 60;
        const uint64_t seconds = input_seconds % 60;

        std::cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds\n";
    }

    return 0;
}
