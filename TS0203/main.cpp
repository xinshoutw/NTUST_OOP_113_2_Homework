////////////////////////////////////////////////////////////////////////////////
/// @brief Print the input string within a square style.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>
#include <string>

int main() {
    std::string input_string;

    // read until EOF
    while (getline(std::cin, input_string)) {
        const int input_length = static_cast<int32_t>(input_string.length());

        // find the minimum n such that n*n >= L.
        const int n = ceil(sqrt(input_length));

        // for each column i from 0 to n-1, traverse each row j.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const int index = j * n + i;

                // only print if the index is within the string length.
                if (index < input_length)
                    std::cout << input_string[index];
            }
            std::cout.put('\n');
        }
    }

    return 0;
}
