#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

unordered_map<char, int> mapp = {{'V', 0}, {'U', 1}, {'C', 2}, {'D', 3}};

int board2int(const string& board) {
    string cpy(board.rbegin(), board.rend());
    int bSize = (int)board.size();

    int result = 0;
    for (int i = 0; i < bSize; ++i) {
        result += mapp[cpy[i]] * pow(4, i);
    }

    return result;
}

void solve() {
    string board1;
    string board2;
    string boardAns;

    cin >> board1 >> board2;

    int b1 = board2int(board1);
    int b2 = board2int(board2);
    int ans;
    char opCode;
    for (int i = 0; i < 3; ++i) {
        cin >> opCode;

        if (opCode == 'A') {
            b2 += b1;
        } else if (opCode == 'L') {
            b2 *= 4;
        } else if (opCode == 'R') {
            b2 /= 4;
        } else if (opCode == 'N') {
        } else {
            assert(false);
        }
    }

    cin >> boardAns;
    ans = board2int(boardAns);
    if (b2 == ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cout << "COWCULATIONS OUTPUT\n";

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; ++i) {
        solve();
    }

    cout << "END OF OUTPUT";

    return 0;
}
