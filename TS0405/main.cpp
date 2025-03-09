////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate CollatzConjecture max steps in a range.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>

int main() {
    std::unordered_map<uint64_t, uint64_t> cache;
    uint64_t input_range_min, input_range_max;

    // read until EOF
    while (std::cin >> input_range_min >> input_range_max) {
        // assign smaller value to input_range_min
        // start from smaller value can make easier to find in the cache
        if (input_range_min > input_range_max) {
            std::swap(input_range_min, input_range_max);
        }

        uint64_t max_steps = 0;
        for (int i = input_range_min; i <= input_range_max; ++i) {
            uint64_t num = i;
            uint64_t ctn = 1;

            while (num != 1) {
                // already in cache
                if (cache.find(num) != cache.end()) {
                    ctn += cache[num] - 1;
                    break;
                }

                if (num & 1) {
                    // odd number
                    num = (num * 3 + 1) / 2;
                    ctn += 2;
                } else {
                    // even number
                    num >>= 1;
                    ctn++;
                }
            }

            cache[i] = ctn;
            max_steps = std::max(max_steps, ctn);
        }

        std::cout << input_range_min << ' ' << input_range_max << ' ' << max_steps << '\n';
    }

    return 0;
}