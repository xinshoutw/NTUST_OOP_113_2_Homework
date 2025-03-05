#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cmath>
#include <thread>

int main() {
    // max_number = (2^(int(input_year - 1900) / 10)) - 1
    // max_number = (2^generation) - 1
    // k! < (2^(generation) - 1 < (k + 1)!
    // ln(k!) < generation * ln(2) - 1 < ln((k+1)!)
    // solve: k

    int32_t input_year;
    while (std::cin >> input_year) {
        const int64_t generation = (input_year - 1900) / 10;
        const int64_t k_bits = 4 * (1LL << generation);
        const double log_max = k_bits * log(2.0); // ln((2^k) - 1) ≈ k * ln(2)

        // ln(n!) ≈ n*ln(n) - n + 0.5 * ln(2πn)
        int64_t n = 1;
        double log_factorial = 0.0;
        while (true) {
            // calculate ln(n!)
            log_factorial = n * log(static_cast<double>(n)) - n + 0.5 * log(2 * M_PI * n);
            if (log_factorial > log_max) {
                break;
            }
            n++;
        }

        std::cout << n - 1 << '\n';
    }

    return 0;
}
