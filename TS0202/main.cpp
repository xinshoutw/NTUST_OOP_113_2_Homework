#include <iostream>
#include <vector>

void getHighScores(std::vector<std::pair<std::string, int>>& memberData) {
    std::sort(memberData.begin(), memberData.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
}

int main() {
    freopen("scores.txt", "r", stdin);

    std::string inputTmpName;
    int inputTmpScore;

    std::vector<std::pair<std::string, int>> memberData;
    while (std::cin >> inputTmpName >> inputTmpScore) {
        memberData.emplace_back(inputTmpName, inputTmpScore);
    }

    getHighScores(memberData);

    for (int i = 0; i < std::min(3, static_cast<int>(memberData.size())); ++i) {
        std::cout << memberData[i].first << '\n' << memberData[i].second << '\n';
    }
}
