#include <complex>
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstring>

int main() {
    std::string input; // X
    int32_t decimal_length_limit; // N
    int32_t full_length_limit; // M

    while (std::cin >> input >> full_length_limit >> decimal_length_limit) {
        getchar();
        const uint8_t padding = getchar(); // C
        const size_t find_index = input.find('.');
        const bool have_decimal_point = find_index != std::string::npos;
        const auto whole_number_length = static_cast<int32_t>(have_decimal_point ? find_index : input.length());
        const int32_t decimal_length = decimal_length_limit + (decimal_length_limit != 0); // include decimal point
        const int32_t padding_length = full_length_limit - whole_number_length - decimal_length;

        // print padding
        for (int i = 0; i < padding_length; ++i) {
            putchar(padding);
        }

        // print whole-number
        if (have_decimal_point) {
            std::cout << input.substr(0, find_index);
        } else {
            std::cout << input;
        }

        // print decimal part (include decimal point)
        int32_t ctn = 0;
        if (decimal_length_limit != 0 && !have_decimal_point) {
            ctn++;
            std::cout << '.';
        } else {
            for (int output_i = static_cast<int32_t>(find_index);
                 ctn < decimal_length && input[output_i] != '\0';
                 ++ctn, ++output_i) {
                std::cout << input[output_i];
            }
        }

        for (; ctn < decimal_length; ++ctn) {
            putchar('0');
        }
        std::cout << '\n';
    }

    return 0;
}
