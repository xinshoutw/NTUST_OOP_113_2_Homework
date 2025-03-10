////////////////////////////////////////////////////////////////////////////////
/// @brief Format input in a specific format.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
    std::string input;            // X
    int32_t decimal_length_limit; // N
    int32_t full_length_limit;    // M
    std::ostringstream output_stream;

    // read until EOF
    while (std::cin >> input >> full_length_limit >> decimal_length_limit) {
        std::cin.get();
        const char padding = std::cin.get(); // C

        // reset output
        output_stream.str("");

        const size_t find_index = input.find('.');
        const bool have_decimal_point = find_index != std::string::npos;

        // add whole-number
        if (have_decimal_point) {
            output_stream << input.substr(0, find_index);
        } else {
            output_stream << input;
        }

        // there is no additional decimal to be added
        if (decimal_length_limit == 0) {
            std::cout << std::right << std::setw(full_length_limit) << std::setfill(padding) << output_stream.str() << '\n';
            continue;
        }

        // input did not have any decimal part
        if (!have_decimal_point) {
            output_stream << '.';

            for (int i = 0; i < decimal_length_limit; ++i) {
                output_stream << '0';
            }
        } else {
            const int32_t printable_decimal_length = std::min(static_cast<int32_t>(input.size() - find_index), decimal_length_limit + 1);
            output_stream << input.substr(find_index, printable_decimal_length);

            for (int i = 0; i < decimal_length_limit - printable_decimal_length + 1; ++i) {
                output_stream << '0';
            }
        }

        std::cout << std::right << std::setw(full_length_limit) << std::setfill(padding) << output_stream.str() << '\n';
    }

    return 0;
}
