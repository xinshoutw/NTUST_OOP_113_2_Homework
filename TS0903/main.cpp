#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int replaceCount, verifyCount;
    vector<bitset<26>> mapper(26);

    while (cin >> replaceCount >> verifyCount) {
        if (replaceCount == 0 && verifyCount == 0)
            return 0;

        for (int i = 0; i < 26; ++i) {
            mapper[i].reset();
            mapper[i].set(i);
        }

        char fromCh, toCh;
        for (int i = 0; i < replaceCount; ++i) {
            cin >> fromCh >> toCh;
            const int from = fromCh - 'a';
            const int to = toCh - 'a';

            for (int c = 0; c < 26; ++c) {
                if (mapper[c][from]) {
                    mapper[c] |= mapper[to];
                }
            }
        }

        string lhs, rhs;
        for (int i = 0; i < verifyCount; ++i) {
            cin >> lhs >> rhs;

            if (lhs.size() != rhs.size()) {
                cout << "no\n";
                continue;
            }

            bool valid = true;
            for (size_t j = 0; j < lhs.size() && valid; ++j) {
                const int from = lhs[j] - 'a';
                const int to = rhs[j] - 'a';
                valid = ((from == to) || (mapper[from][to]));
            }

            cout << (valid ? "yes\n" : "no\n");
        }
    }

    return 0;
}