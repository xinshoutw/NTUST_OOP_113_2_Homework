#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    // Process each input line separately.
    while (getline(cin, s)) {
        if (s.empty())
            continue; // Skip empty lines if any.

        int L = s.length();
        // Find the minimum n such that n*n >= L.
        int n = ceil(sqrt(L));

        // For each column j from 0 to n-1, traverse each row i.
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                int index = i * n + j;
                // Only print if index is within the string length.
                if (index < L)
                    cout << s[index];
            }
            cout << "\n";
        }
    }
    return 0;
}
