#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#define YX2Pos(y, x) (y * 4 + x)

bool isPossible(const char* board, const char* str, const int y, const int x, bool* visited) { // NOLINT(*-no-recursion)
    if (x < 0 || x >= 4 || y < 0 || y >= 4 || visited[YX2Pos(y, x)] || board[YX2Pos(y, x)] != *str)
        return false;

    if (*(str + 1) == '\0')
        return true;

    visited[YX2Pos(y, x)] = true;

    // clang-format off
    const bool possible =
        isPossible(board, str + 1, y - 1, x - 1, visited) ||
        isPossible(board, str + 1, y - 1, x,     visited) ||
        isPossible(board, str + 1, y - 1, x + 1, visited) ||
        isPossible(board, str + 1, y,     x - 1, visited) ||
        isPossible(board, str + 1, y,     x + 1, visited) ||
        isPossible(board, str + 1, y + 1, x - 1, visited) ||
        isPossible(board, str + 1, y + 1, x,     visited) ||
        isPossible(board, str + 1, y + 1, x + 1, visited);
    // clang-format on

    visited[YX2Pos(y, x)] = false;
    return possible;
}

int main() {
    char board[16];

    while (std::cin >> board[0]) {
        for (int i = 1; i < 16; ++i)
            std::cin >> board[i];

        int boardAppearCount[26]{};
        for (const char& i : board)
            boardAppearCount[i - 'a']++;

        std::fstream fs("words.txt", std::fstream::in);
        std::string word;
        while (fs >> word) {
            bool impossible = false;
            int wordAppearCount[26]{};

            for (const char& i : word) {
                if (boardAppearCount[i - 'a'] > ++wordAppearCount[i - 'a']) {
                    impossible = true;
                    break;
                }
            }

            if (impossible)
                continue;

            for (int i = 0; i < 16; ++i) {
                if (board[i] == word[0]) {
                    bool visited[16]{}; // declare here for GC collect
                    if (isPossible(board, word.c_str(), i / 4, i % 4, visited)) {
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