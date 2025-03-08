////////////////////////////////////////////////////////////////////////////////
/// @brief Read "grade.txt" as an input.
///        Count each grade appear count.
///        Write into "grades.Output".
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdint>

int main() {
    // redirect input and output to specific files
    freopen("grade.txt", "r", stdin);
    freopen("grades.Output", "w", stdout);

    int32_t input_appear[6] = {0};
    int32_t input_tmp;

    // read until EOF
    while (std::cin >> input_tmp) {
        input_appear[input_tmp]++;
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << input_appear[i] << " grade(s) of " << i << '\n';
    }

    return 0;
}
