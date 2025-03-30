#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ySize, xSize;
    while (cin >> ySize >> xSize) {
        if (ySize < 1 || ySize > 300 || xSize < 1 || xSize > 300) {
            cout << "Invalid grid size\n";
            continue;
        }

        const auto mapp = new bool[xSize * ySize];
        queue<pair<int, int>> mappQ; // x, y
        for (int y = 0; y < ySize; ++y) {
            bool connectFlag = false;
            for (int x = 0; x < xSize; ++x) {
                cin >> mapp[y * xSize + x];
                if (mapp[y * xSize + x]) {
                    if (!connectFlag) {
                        connectFlag = true;
                        mappQ.emplace(x, y);
                    }
                } else {
                    connectFlag = false;
                }
            }
        }

        int maxGroupSize = 0;
        int groupCount = 0;
        while (!mappQ.empty()) {
            int xPos = mappQ.front().first;
            int yPos = mappQ.front().second;
            mappQ.pop();
            if (!mapp[yPos * xSize + xPos]) {
                continue;
            }

            queue<pair<int, int>> groupQ; // x, y
            groupQ.emplace(xPos, yPos);
            mapp[yPos * xSize + xPos] = false;

            int groupSize = 0;
            groupCount++;
            while (!groupQ.empty()) {
                int x = groupQ.front().first;
                int y = groupQ.front().second;
                groupQ.pop();

                groupSize++;
                if (x > 0 && mapp[y * xSize + (x - 1)]) { // check left
                    groupQ.emplace(x - 1, y);
                    mapp[y * xSize + (x - 1)] = false;
                }

                if (y > 0 && mapp[((y - 1) * xSize + x)]) { // check up
                    groupQ.emplace(x, y - 1);
                    mapp[((y - 1) * xSize + x)] = false;
                }

                if ((x < xSize - 1) && mapp[(y * xSize + (x + 1))]) { // check right
                    groupQ.emplace(x + 1, y);
                    mapp[(y * xSize + (x + 1))] = false;
                }

                if ((y < ySize - 1) && mapp[((y + 1) * xSize + x)]) { // check down
                    groupQ.emplace(x, y + 1);
                    mapp[((y + 1) * xSize + x)] = false;
                }
            }

            maxGroupSize = max(groupSize, maxGroupSize);
        }

        cout << groupCount << ' ' << maxGroupSize << '\n';

        delete[] mapp;
    }
}
