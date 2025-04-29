#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row1, col1;
    int row2, col2;

    cin >> row1 >> col1 >> row2 >> col2;
    vector<int> matrix1(row1 * col1, 0);
    vector<int> matrix2(row2 * col2, 0);
    vector<int> result(row1 * col2, 0);

    for (int i = 0; i < row1 * col1; ++i) {
        cin >> matrix1[i];
    }
    for (int i = 0; i < row2 * col2; ++i) {
        cin >> matrix2[i];
    }

    if (col1 != row2) {
        cout << "Matrix multiplication failed.\n";
        return 0;
    }

    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i * col2 + j] += matrix1[i * col1 + k] * matrix2[k * col2 + j];
            }
        }
    }

    for (int i = 0; i < row1; ++i) {
        cout << result[i * col2];
        for (int j = 1; j < col2; ++j) {
            cout << " " << result[i * col2 + j];
        }
        cout << endl;
    }
}