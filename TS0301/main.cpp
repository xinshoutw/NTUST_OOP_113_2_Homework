////////////////////////////////////////////////////////////////////////////////
/// @brief Read numbers until EOF, print appear times and sort by numbers.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/08
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <cstdint>
#include <iostream>
#include <map>

int main() {
    std::map<int64_t, int64_t> appear_count;
    int64_t input_tmp;

    // read until EOF
    while (std::cin >> input_tmp) {
        appear_count[input_tmp]++;
    }

    std::cout << "N\tcount\n";
    for (auto i = appear_count.rbegin(); i != appear_count.rend(); ++i) {
        std::cout << i->first << '\t' << i->second << '\n';
    }

    return 0;
}
