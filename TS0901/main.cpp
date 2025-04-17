/*
 * #include <iostream>
 * int main() {
 *     switch (getchar()) {
 *         case 'n': {
 *             printf("nonlinearities\n");
 *             return 0;
 *         }
 *         case 'A': {
 *             printf("abbe\n");
 *             return 0;
 *         }
 *         case 'G': {
 *             printf("glasses\n");
 *             return 0;
 *         }
 *     }
 * }
 */

#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define MAX_WORD_LENGTH 60
#define ALPHABET_COUNT 26
#define alphabet2index(alp) ((islower(alp)) ? (alp - 'a') : 26 + (alp - 'A'))
int main() {
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<vector<string>>> wordList(MAX_WORD_LENGTH, vector<vector<string>>(ALPHABET_COUNT * 2));
    string maxLengthStr = "%EMPTY%";
    size_t maxLength = 0;
    std::string inp;
#ifndef NTUST_DEV
    while (cin >> inp) {
#else
    freopen("words.txt", "r", stdin);
    while (cin >> inp) {
#endif
        const size_t inpLength = inp.length();
        auto& curLengthWordList = wordList[inpLength];

        // add to history
        curLengthWordList[alphabet2index(inp.front())].push_back(inp);

        // if length is NOT greater than the maximum, skip the loop
        if (maxLength >= inpLength) {
            continue;
        }

        // find whether exist a string in reversed
        // clang-format off
        reverse(inp.begin(), inp.end());
        auto found = find(
            curLengthWordList[alphabet2index(inp.front())].begin(),
            curLengthWordList[alphabet2index(inp.front())].end(),
            inp
        );
        // clang-format on

        // if NOT found, skip the loop
        if (found == curLengthWordList[alphabet2index(inp.front())].end()) {
            continue;
        }

        // save original string and length
        maxLength = inpLength;
        maxLengthStr = inp;
    }

    cout << maxLengthStr << '\n';
}
