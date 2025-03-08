////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate math puzzle.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <cstdint>
#include <iostream>
#include <thread>

int main() {
    // val generation = int(input_year - 1900) / 10)
    // val k_bits = (4 * (2 << generation)) - 1 ~ (4 * (2 << generation))
    // k! < k_bits < (k + 1)!
    // ln(k!) < generation * ln(2) < ln((k+1)!)
    // solve: k

    int32_t input_year;

    // read until EOF
    while (std::cin >> input_year) {
        const int64_t generation = (input_year - 1900) / 10;
        const int64_t k_bits = 4 * (1LL << generation);
        const double log_max = k_bits * log(2.0); // ln((2^k) - 1) ~ ln(2^k) = k * ln(2)

        // ln(n!) ~ n*ln(n) - n + 0.5 * ln(2πn)
        int64_t n = 0;
        double log_factorial = 0.0;

        // calculate ln(n!)
        do {
            n++;
            log_factorial = n * log(static_cast<double>(n)) - n + 0.5 * log(2 * M_PI * n);
        } while (log_factorial <= log_max);

        std::cout << n - 1 << '\n';
    }

    return 0;
}
