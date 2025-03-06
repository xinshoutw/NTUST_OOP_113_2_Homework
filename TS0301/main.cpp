#include <iostream>
#include <vector>
#include <set>
#include <cstdint>
#include <algorithm>

int main() {
    std::vector<int64_t> inputInts;
    int64_t inputTmp;
    std::set<int64_t> inputSet;
    while (std::cin >> inputTmp) {
        inputInts.push_back(inputTmp);
        inputSet.insert(inputTmp);
    }

    // number, appearCount
    std::vector<std::pair<int64_t, int64_t>> sortedResult;
    sortedResult.reserve(inputSet.size());
    for (auto i : inputSet) {
        sortedResult.emplace_back(
            i, static_cast<int64_t>(std::count(inputInts.begin(), inputInts.end(), i))
        );
    }

    std::sort(
        sortedResult.begin(),
        sortedResult.end(),
        [](const std::pair<int64_t, int64_t>& l, const std::pair<int64_t, int64_t>& r) {
            return l.first < r.first;
        }
    );

    std::cout << "N\tcount\n";
    for (const auto& i : sortedResult) {
        std::cout << i.first << '\t' << i.second << '\n';
    }

    return 0;
}
