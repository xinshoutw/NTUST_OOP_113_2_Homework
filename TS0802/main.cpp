#include <iostream>

using namespace std;

int main() {
    int64_t ySize1, xSize1, ySize2, xSize2;
    cin >> ySize1 >> xSize1 >> ySize2 >> xSize2;

    const auto m1 = new int[ySize1 * xSize1];
    const auto m2 = new int[ySize2 * xSize2];

    for (int y = 0; y < ySize1; ++y) {
        for (int x = 0; x < xSize1; ++x) {
            cin >> m1[y * xSize1 + x];
        }
    }

    for (int y = 0; y < ySize2; ++y) {
        for (int x = 0; x < xSize2; ++x) {
            cin >> m2[y * xSize2 + x];
        }
    }

    if (xSize1 != ySize2) {
        cout << "Matrix multiplication failed.\n";

        delete[] m1;
        delete[] m2;
        return 0;
    }

    for (int y = 0; y < ySize1; ++y) {
        for (int x = 0; x < xSize2; ++x) {
            int result = 0;

            for (int i = 0; i < xSize1; ++i) {
                result += m1[y * xSize1 + i] * m2[x + i * xSize2];
            }

            cout << result << (x == xSize2 - 1 ? "" : " ");
        }
        cout << '\n';
    }

    delete[] m1;
    delete[] m2;
}
