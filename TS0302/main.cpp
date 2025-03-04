#include <iostream>
#include <cstdint>

int main() {
    freopen("grade.txt", "r", stdin);
    freopen("grades.Output", "w", stdout);

    int32_t inputAppear[6] = {0};
    int32_t inputTmp;
    while (std::cin >> inputTmp) {
        inputAppear[inputTmp]++;
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << inputAppear[i] << " grade(s) of " << i << '\n';
    }

    return 0;
}
