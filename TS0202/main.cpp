////////////////////////////////////////////////////////////////////////////////
/// @brief Read file and print the most three highest score and name
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

/**
 * @brief Sort the vector by the largest score first.
 * @param member_data include pairs of name and score
 */
void GetHighScores(std::vector<std::pair<std::string, int>>& member_data) {
    std::sort(member_data.begin(), member_data.end(), [](const auto& l, const auto& r) {
        return l.second > r.second;
    });
}

int main() {
    freopen("scores.txt", "r", stdin);

    std::string input_tmp_name;
    int input_tmp_score;

    std::vector<std::pair<std::string, int>> member_data;
    while (std::cin >> input_tmp_name >> input_tmp_score) {
        member_data.emplace_back(input_tmp_name, input_tmp_score);
    }

    GetHighScores(member_data);

    // print at most 3 members scoreboard
    for (int i = 0; i < std::min(3, static_cast<int>(member_data.size())); ++i) {
        std::cout << member_data[i].first << '\n' << member_data[i].second << '\n';
    }

    return 0;
}
