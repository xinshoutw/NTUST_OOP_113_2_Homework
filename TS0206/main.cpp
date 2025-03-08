////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate the tax from input income.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

// each range of the highest money limit
const std::vector<uint16_t> MONEY_RANGE_MAX = {0, 750, 2250, 3750, 5250, 7000};

// each range of money offset
const std::vector<double> MONEY_OFFSETS = {0, 7.5, 37.5, 82.5, 142.5, 230};

// each range of tax rate
const std::vector<double> MONEY_RATE = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06};

int main() {
    // input of positive number
    uint32_t input_income;

    // adjust to 2 tailing decimal
    std::cout << std::setprecision(2) << std::fixed;

    // read until EOF
    while (std::cin >> input_income) {
        // find first value 'index' which less or equals to input_income
        const int64_t index = std::upper_bound(MONEY_RANGE_MAX.begin(), MONEY_RANGE_MAX.end(), input_income) - MONEY_RANGE_MAX.begin() - 1;

        std::cout << MONEY_OFFSETS[index] + (input_income - MONEY_RANGE_MAX[index]) * (MONEY_RATE[index]) << '\n';
    }

    return 0;
}
