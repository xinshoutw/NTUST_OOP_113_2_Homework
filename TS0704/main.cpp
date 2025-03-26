#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void solve(const string& inp1, const string& inp2) {
    const int xSize = static_cast<int>(inp1.size()) + 1;
    const int ySize = static_cast<int>(inp2.size()) + 1;
    const auto dp = new int[xSize * ySize]();

    // init table
    for (int x = 0; x < xSize; ++x) {
        dp[x] = x;
    }
    for (int y = 0; y < ySize; ++y) {
        dp[y * xSize] = y;
    }

    // calculate table
    for (int y = 1; y < ySize; ++y) {
        for (int x = 1; x < xSize; ++x) {
            if (inp1[x - 1] == inp2[y - 1]) {
                dp[y * xSize + x] = dp[(y - 1) * xSize + (x - 1)]; // left up
                continue;
            }

            const int minStep = min(min(dp[(y - 1) * xSize + x], dp[y * xSize + (x - 1)]), dp[(y - 1) * xSize + (x - 1)]);
            dp[y * xSize + x] = minStep + 1;
        }
    }

    cout << dp[xSize * ySize - 1] << '\n';

    delete[] dp;
}

int main() {
    string input1, input2;
    while (getline(cin, input1)) {
        if (!getline(cin, input2))
            break;

        solve(input1, input2);
    }
}
