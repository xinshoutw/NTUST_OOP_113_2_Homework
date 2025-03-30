#include <iostream>
#include <string>

using namespace std;

int main() {
    string inputStr;
    while (getline(cin, inputStr)) {
        int strSize = static_cast<int>(inputStr.size());
        int gridSize = ceil(sqrt(strSize));

        for (int x = 0; x < gridSize; ++x) {
            for (int y = 0; y < gridSize; ++y) {
                if (y * gridSize + x >= strSize) {
                    break;
                }
                cout << inputStr[y * gridSize + x];
            }
            cout << '\n';
        }
    }
}
