#include <array>
#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

namespace {
constexpr int ROWS = 6;
constexpr int COLS = 6;
constexpr int PADDED_ROWS = ROWS + 2;
constexpr int PADDED_COLS = COLS + 2;
constexpr char EMPTY = '0';

constexpr std::array<int, 4> dx = {0, 1, 0, -1};
constexpr std::array<int, 4> dy = {-1, 0, 1, 0};

constexpr int INF = std::numeric_limits<int>::max();
} // namespace

class LianLianKan {
public:
    LianLianKan() {
        initializeBoard();
    }

    void initializeBoard() {
        for (auto& row : board) {
            row.fill(EMPTY);
        }
    }

    void readBoard() {
        for (int i = 0; i < ROWS; ++i) {
            std::string line;
            std::getline(std::cin, line);
            std::istringstream iss(line);

            for (int j = 0; j < COLS; ++j) {
                int tileValue;
                iss >> tileValue;

                board[i + 1][j + 1] = static_cast<char>(tileValue);
            }
        }
    }

    void processPairRequests() {
        int x1, y1, x2, y2;
        while (std::cin >> x1 >> y1 >> x2 >> y2) {

            const int startY = y1 + 1;
            const int startX = x1 + 1;
            const int targetY = y2 + 1;
            const int targetX = x2 + 1;

            if (isValidPair(startY, startX, targetY, targetX)) {

                board[startY][startX] = board[targetY][targetX] = EMPTY;
                std::cout << "pair matched" << '\n';
            } else {
                std::cout << "bad pair" << '\n';
            }
        }
    }

private:
    std::array<std::array<char, PADDED_COLS>, PADDED_ROWS> board{};

    struct State {
        int y, x;
        int dir;
        int turns;

        bool operator>(const State& other) const {
            return turns > other.turns;
        }
    };

    static bool isInBounds(const int x, const int y) {
        return x >= 0 && x < PADDED_COLS && y >= 0 && y < PADDED_ROWS;
    }

    bool isValidPair(const int startY, const int startX, const int targetY, const int targetX) const {

        if (startY == targetY && startX == targetX) {
            return false;
        }

        if (board[startY][startX] == EMPTY || board[targetY][targetX] == EMPTY) {
            return false;
        }

        if (board[startY][startX] != board[targetY][targetX]) {
            return false;
        }

        return canConnect(startY, startX, targetY, targetX);
    }

    bool canConnect(const int startY, const int startX, const int targetY, const int targetX) const {
        std::array<std::array<std::array<int, 4>, PADDED_COLS>, PADDED_ROWS> visited{};

        for (auto& row : visited) {
            for (auto& cell : row) {
                cell.fill(INF);
            }
        }

        std::priority_queue<State, std::vector<State>, std::greater<>> q;

        for (int dir = 0; dir < 4; ++dir) {
            const int newY = startY + dy[dir];
            const int newX = startX + dx[dir];

            if (!isInBounds(newX, newY) || (board[newY][newX] != EMPTY && (newY != targetY || newX != targetX))) {
                continue;
            }

            visited[newY][newX][dir] = 0;
            q.push({newY, newX, dir, 0});
        }

        while (!q.empty()) {
            const auto current = q.top();
            q.pop();

            if (current.y == targetY && current.x == targetX) {
                return true;
            }

            if (current.turns > visited[current.y][current.x][current.dir]) {
                continue;
            }

            for (int dir = 0; dir < 4; ++dir) {

                const int newTurns = current.turns + (dir == current.dir ? 0 : 1);

                if (newTurns > 2) {
                    continue;
                }

                int newY = current.y + dy[dir];
                int newX = current.x + dx[dir];

                while (isInBounds(newX, newY) && (board[newY][newX] == EMPTY || (newY == targetY && newX == targetX))) {

                    if (newTurns < visited[newY][newX][dir]) {
                        visited[newY][newX][dir] = newTurns;
                        q.push({newY, newX, dir, newTurns});

                        if (newY == targetY && newX == targetX) {
                            continue;
                        }
                    }

                    newY += dy[dir];
                    newX += dx[dir];
                }
            }
        }

        return false;
    }
};

void solve() {
    LianLianKan game;
    game.readBoard();
    game.processPairRequests();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}