#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#define posToRC(pos) {pos / 4, pos % 4}

auto isPossible(const char* board, const char* str, const int curPos, bool* visited) -> bool {
    if (*str == '\0')
        return true;

    if (visited[curPos])
        return false;

    visited[curPos] = true;

    // y(row), x(col)
    const std::pair<int, int> rc = posToRC(curPos);
    bool result = false;

    // lu
    if (rc.first > 0 && rc.second > 0 && board[curPos - 5] == str[0]) {
        if (isPossible(board, str + 1, curPos - 5, visited)) result = true;
    }

    // u
    if (!result && rc.first > 0 && board[curPos - 4] == str[0]) {
        if (isPossible(board, str + 1, curPos - 4, visited)) result = true;
    }

    // ru
    if (!result && rc.first > 0 && rc.second < 3 && board[curPos - 3] == str[0]) {
        if (isPossible(board, str + 1, curPos - 3, visited)) result = true;
    }

    // l
    if (!result && rc.second > 0 && board[curPos - 1] == str[0]) {
        if (isPossible(board, str + 1, curPos - 1, visited)) result = true;
    }

    // r
    if (!result && rc.second < 3 && board[curPos + 1] == str[0]) {
        if (isPossible(board, str + 1, curPos + 1, visited)) result = true;
    }

    // ld
    if (!result && rc.first < 3 && rc.second > 0 && board[curPos + 3] == str[0]) {
        if (isPossible(board, str + 1, curPos + 3, visited)) result = true;
    }

    // d
    if (!result && rc.first < 3 && board[curPos + 4] == str[0]) {
        if (isPossible(board, str + 1, curPos + 4, visited)) result = true;
    }

    // rd
    if (!result && rc.first < 3 && rc.second < 3 && board[curPos + 5] == str[0]) {
        if (isPossible(board, str + 1, curPos + 5, visited)) result = true;
    }

    visited[curPos] = false;  // Backtrack
    return result;
}

int main() {
    char board[16];

    while (std::cin >> board[0]) {
        for (int i = 1; i < 16; ++i) {
            std::cin >> board[i];
        }

        std::unordered_map<char, int> charCount;
        for (const char& i : board) {
            charCount[i]++;
        }

        std::fstream fs;
        fs.open("words.txt", std::fstream::in);
        if (!fs.is_open()) {
            return 1;
        }

        std::string word;
        while (fs >> word) {
            std::unordered_map<char, int> tempCount = charCount;
            bool impossible = false;

            for (char c : word) {
                if (--tempCount[c] < 0) {
                    impossible = true;
                    break;
                }
            }

            if (impossible) continue;

            for (int i = 0; i < 16; ++i) {
                if (board[i] == word[0]) {
                    bool visited[16] = {false};
                    if (isPossible(board, word.c_str() + 1, i, visited)) {
                        std::cout << word << '\n';
                        break;
                    }
                }
            }
        }
        std::cout << '\n';
        fs.close();
    }
}
