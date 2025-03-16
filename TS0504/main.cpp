////////////////////////////////////////////////////////////////////////////////
/// @brief
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/17
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>
#include <vector>

bool verify_sudoku(const std::vector<char>& smap);

int main() {
    std::vector<char> sudoku_map;
    sudoku_map.reserve(81);
    while (!std::cin.eof()) {
        sudoku_map.clear();

        for (int i = 0; i < 81; ++i) {
            sudoku_map.push_back(static_cast<char>(std::cin.get() - '0'));
            std::cin.get(); // ignore ',' or '\n'
        }

        if (verify_sudoku(sudoku_map)) {
            std::cout << "True\n";
        } else {
            std::cout << "False\n";
        }

        std::cin >> std::ws; // skip last '\n' and ' '
    }
}

bool verify_sudoku(const std::vector<char>& smap) {
    // check horizons
    for (int y = 0; y < 9; ++y) {
        std::set<char> appear;

        for (int x = 0; x < 9; ++x) {
            appear.insert(smap[9 * y + x]);
        }

        if (static_cast<int>(appear.size()) != 9)
            return false;
    }

    // check verticals
    for (int x = 0; x < 9; ++x) {
        std::set<char> appear;

        for (int y = 0; y < 9; ++y) {
            appear.insert(smap[9 * y + x]);
        }

        if (static_cast<int>(appear.size()) != 9)
            return false;
    }

    // check square box
    for (int y = 0; y < 9; y += 3) {
        std::set<char> appear;
        for (int x = 0; x < 9; x += 3) {
            appear.insert(smap[9 * y + x]);
            appear.insert(smap[9 * y + (x + 1)]);
            appear.insert(smap[9 * y + (x + 2)]);
            appear.insert(smap[9 * (y + 1) + x]);
            appear.insert(smap[9 * (y + 1) + (x + 1)]);
            appear.insert(smap[9 * (y + 1) + (x + 2)]);
            appear.insert(smap[9 * (y + 2) + x]);
            appear.insert(smap[9 * (y + 2) + (x + 1)]);
            appear.insert(smap[9 * (y + 2) + (x + 2)]);
        }

        if (static_cast<int>(appear.size()) != 9)
            return false;
    }

    return true;
}
