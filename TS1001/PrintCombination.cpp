//
// Created by xinshou on 2025/4/22.
//

#include "PrintCombination.h"
#include <string>

void PrintCombination(int* arrayPtr, const int ELEMENTS_FOR_COMBINATION, const int ELEMENTS_FOR_CHOICE, const std::string& curStr) { // NOLINT(*-no-recursion)
    if (ELEMENTS_FOR_CHOICE == 0) {
        std::string curCpy = curStr;
        curCpy.pop_back();
        std::cout << curCpy << '\n';
        return;
    }

    for (int i = 0; i <= ELEMENTS_FOR_COMBINATION - ELEMENTS_FOR_CHOICE; ++i) {
        PrintCombination(
            // clang-format off
            arrayPtr + 1 + i,
            ELEMENTS_FOR_COMBINATION - 1 - i,
            ELEMENTS_FOR_CHOICE - 1,
            curStr + std::to_string(arrayPtr[i]) + ' '
            // clang-format on
        );
    }
}