#include <iostream>
#include <cstdint>
#include <iomanip>

int main() {
    double input_double; // X
    int32_t deciLimit; // N
    int32_t full_length_limit; // M
    char padding; // C

    while (std::cin >> input_double >> full_length_limit >> deciLimit >> padding) {
        std::cout.precision(deciLimit);
        std::cout <<
            std::setw(full_length_limit) << std::setfill(padding) << std::right << std::fixed << input_double << '\n';
    }

    return 0;
}
