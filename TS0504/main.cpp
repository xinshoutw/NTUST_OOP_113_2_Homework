////////////////////////////////////////////////////////////////////////////////
/// @brief Verification program that checks if a given 9x9 grid follows Sudoku rules
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/17
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

bool verify_sudoku(const std::vector<int>& smap);

int main() {
    std::vector<int> sudoku_map;
    sudoku_map.reserve(81);
    std::string input_str;

    while (getline(std::cin, input_str)) {
        if (input_str.empty()) continue;

        for (const auto& i : input_str) {
            if (i != ',')
                sudoku_map.push_back(i - '0' - 1); // map 1 ~ 9 to 0 ~ 8

            if (static_cast<int>(sudoku_map.size()) == 81) {
                if (verify_sudoku(sudoku_map)) {
                    std::cout << "True\n";
                } else {
                    std::cout << "False\n";
                }
                sudoku_map.clear();
            }
        }
    }
}

bool verify_sudoku(const std::vector<int>& smap) {
    // check horizons
    for (int y = 0; y < 9; ++y) {
        int counter = 0;
        for (int x = 0; x < 9; ++x) {
            counter += (1 << smap[9 * y + x]);
        }

        if (counter != 0b111111111)
            return false;
    }

    // check verticals
    for (int x = 0; x < 9; ++x) {
        int counter = 0;
        for (int y = 0; y < 9; ++y) {
            counter += (1 << smap[9 * y + x]);
        }

        if (counter != 0b111111111)
            return false;
    }

    // check square box
    for (int y = 0; y < 9; y += 3) {
        for (int x = 0; x < 9; x += 3) {
            int counter = 0;
            counter += (1 << smap[9 * y + x]);
            counter += (1 << smap[9 * y + (x + 1)]);
            counter += (1 << smap[9 * y + (x + 2)]);
            counter += (1 << smap[9 * (y + 1) + x]);
            counter += (1 << smap[9 * (y + 1) + (x + 1)]);
            counter += (1 << smap[9 * (y + 1) + (x + 2)]);
            counter += (1 << smap[9 * (y + 2) + x]);
            counter += (1 << smap[9 * (y + 2) + (x + 1)]);
            counter += (1 << smap[9 * (y + 2) + (x + 2)]);

            if (counter != 0b111111111)
                return false;
        }
    }

    return true;
}
