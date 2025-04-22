#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#define posToRC(pos) {pos / 4, pos % 4}

bool isPossible(const char* board, const char* str, const int curPos, bool* visited) {
    if (visited[curPos] || board[curPos] != *str)
        return false;

    if (*(str + 1) == '\0')
        return true;

    const std::pair<int, int> rc = posToRC(curPos);

    visited[curPos] = true;
    bool result = false;

    if (rc.first > 0 && rc.second > 0)
        result = result || isPossible(board, str + 1, curPos - 5, visited);

    if (rc.first > 0)
        result = result || isPossible(board, str + 1, curPos - 4, visited);

    if (rc.first > 0 && rc.second < 3)
        result = result || isPossible(board, str + 1, curPos - 3, visited);

    if (rc.second > 0)
        result = result || isPossible(board, str + 1, curPos - 1, visited);

    if (rc.second < 3)
        result = result || isPossible(board, str + 1, curPos + 1, visited);

    if (rc.first < 3 && rc.second > 0)
        result = result || isPossible(board, str + 1, curPos + 3, visited);

    if (rc.first < 3)
        result = result || isPossible(board, str + 1, curPos + 4, visited);

    if (rc.first < 3 && rc.second < 3)
        result = result || isPossible(board, str + 1, curPos + 5, visited);

    visited[curPos] = false;
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

            if (impossible)
                continue;

            for (int i = 0; i < 16; ++i) {
                if (board[i] == word[0]) {
                    bool visited[16] = {false};
                    if (isPossible(board, word.c_str(), i, visited)) {
                        std::cout << word << '\n';
                        break;
                    }
                }
            }
        }
        std::cout << '\n';
        fs.close();
    }

    return 0;
}