#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    uint64_t inputIncome;
    const std::vector<uint16_t> MONEY_RANGE_MAX =
        {0, 750, 2250, 3750, 5250, 7000}; // range of rate's max money

    const std::vector<double> MONEY_OFFSETS =
        {0, 7.5, 37.5, 82.5, 142.5, 230}; // each begining money

    std::cout.precision(2);
    while (std::cin >> inputIncome) {
        bool printed = false;
        for (int i = 0; i < static_cast<int>(MONEY_RANGE_MAX.size()); ++i) {
            if (inputIncome > MONEY_RANGE_MAX[i]) {
                continue;
            }

            std::cout << std::fixed <<
                MONEY_OFFSETS[i - 1] + (inputIncome - MONEY_RANGE_MAX[i - 1]) * (0.01 * i) << std::endl;

            printed = true;
            break;
        }

        if (!printed) {
            std::cout << std::fixed <<
                MONEY_OFFSETS[5] + (inputIncome - MONEY_RANGE_MAX[5]) * (0.01 * 6) << std::endl;
        }
    }


    return 0;
}
