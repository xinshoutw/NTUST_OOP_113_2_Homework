#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check1(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Straight Flush

    const int type = cards.front().first;
    for (const auto& i : cards) {
        // check type
        if (i.first != type) {
            return false;
        }
    }

    int lastNum = cards.front().second;
    if (lastNum == 1) {
        // check 1, 10, 11, 12, 13
        if (cards[1].second == 10 && cards[2].second == 11 && cards[3].second == 12 && cards[4].second == 13) {
            return true;
        }
    }

    for (int i = 1; i < 5; ++i) {
        if (lastNum + 1 != cards[i].second) {
            return false;
        }
        lastNum++;
    }

    return true;
}

bool check2(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Four of a Kind

    int num0 = switchedCards[0].second;
    int num1 = switchedCards[1].second;
    int num2 = switchedCards[2].second;
    int num3 = switchedCards[3].second;
    int num4 = switchedCards[4].second;

    if (num0 == num1) {
        // check 1 1 1 1 2
        return num0 == num3;
    } else {
        // check 1 2 2 2 2
        return num4 == num1;
    }
}

bool check3(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Full House

    int num0 = switchedCards[0].second;
    int num1 = switchedCards[1].second;
    int num2 = switchedCards[2].second;
    int num3 = switchedCards[3].second;
    int num4 = switchedCards[4].second;

    if (num0 == num1 && num0 == num2) {
        // check 1 1 1 2 2
        return num3 == num4;
    } else if (num2 == num3 && num2 == num4) {
        // check 1 1 2 2 2
        return num0 == num1;
    }

    return false;
}

bool check4(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Flush

    int type = cards.front().first;
    return all_of(cards.begin(), cards.end(), [&type](const pair<int, int>& i) {
        return i.first == type;
    });
}

bool check5(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Straight

    int lastNum = switchedCards.front().second;
    if (lastNum == 1) {
        // check 1, 10, 11, 12, 13
        if (switchedCards[1].second == 10 && switchedCards[2].second == 11 && switchedCards[3].second == 12 && switchedCards[4].second == 13) {
            return true;
        }
    }

    for (int i = 1; i < 5; ++i) {
        if (lastNum + 1 != switchedCards[i].second) {
            return false;
        }
        lastNum++;
    }

    return true;
}

bool check6(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Three of a Kind

    int num0 = switchedCards[0].second;
    int num1 = switchedCards[1].second;
    int num2 = switchedCards[2].second;
    int num3 = switchedCards[3].second;
    int num4 = switchedCards[4].second;

    if (num0 == num1 && num0 == num2) {
        // check 1 1 1 x x
        return true;
    } else if (num1 == num2 && num1 == num3) {
        // check x 1 1 1 x
        return true;
    } else if (num2 == num3 && num2 == num4) {
        // check x x 1 1 1
        return true;
    }

    return false;
}

bool check7(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // Two Pair

    int num0 = switchedCards[0].second;
    int num1 = switchedCards[1].second;
    int num2 = switchedCards[2].second;
    int num3 = switchedCards[3].second;
    int num4 = switchedCards[4].second;

    if (num0 == num1) {
        // check 1 1 2 2 x
        // check 1 1 x 2 2
        return num2 == num3 || num3 == num4;
    } else if (num1 == num2 && num3 == num4) {
        // check x 1 1 2 2
        return true;
    }

    return false;
}

bool check8(const vector<pair<int, int>>& cards, const vector<pair<int, int>>& switchedCards) {
    // One Pair

    int num0 = switchedCards[0].second;
    int num1 = switchedCards[1].second;
    int num2 = switchedCards[2].second;
    int num3 = switchedCards[3].second;
    int num4 = switchedCards[4].second;

    return num0 == num1 || num1 == num2 || num2 == num3 || num3 == num4;
}

string parse(const vector<pair<string, string>>& cardsRaw) {
    vector<pair<int, int>> cards;         // typeRank [0 ,1 ,2 ,3], numberValue
    vector<pair<int, int>> switchedCards; // numberValue, typeRank [0 ,1 ,2 ,3]

    // initcialize variables
    // validate and convert to int
    if (static_cast<int>(cardsRaw.size()) != 5) {
        return "Invalid Input";
    }

    for (const auto& i : cardsRaw) {
        int typeRank;
        int numberValue;

        // check type valid
        if (static_cast<int>(i.first.size()) == 1) {
            if (i.first[0] == 'S')
                typeRank = 0;
            else if (i.first[0] == 'H')
                typeRank = 1;
            else if (i.first[0] == 'D')
                typeRank = 2;
            else if (i.first[0] == 'C')
                typeRank = 3;
            else {
                return "Invalid Input";
            }
        } else {
            return "Invalid Input";
        }

        // check number valid
        if (static_cast<int>(i.second.size()) == 1) {
            if (i.second == "0" || i.second == "1") {
                return "Invalid Input";
            } else if (isdigit(i.second[0])) {
                numberValue = i.second[0] - '0';
            } else if (i.second == "A") {
                numberValue = 1;
            } else if (i.second == "J") {
                numberValue = 11;
            } else if (i.second == "Q") {
                numberValue = 12;
            } else if (i.second == "K") {
                numberValue = 13;
            } else {
                return "Invalid Input";
            }
        } else if (static_cast<int>(i.second.size()) == 2) {
            if (i.second == "10") {
                numberValue = 10;
            } else {
                return "Invalid Input";
            }
        } else {
            return "Invalid Input";
        }

        cards.emplace_back(typeRank, numberValue);
        switchedCards.emplace_back(typeRank, numberValue);
    }

    sort(cards.begin(), cards.end());
    sort(switchedCards.begin(), switchedCards.end(), [](pair<int, int>& lhs, pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    });

    if (check1(cards, switchedCards))
        return "Straight Flush";
    if (check2(cards, switchedCards))
        return "Four of a Kind";
    if (check3(cards, switchedCards))
        return "Full House";
    if (check4(cards, switchedCards))
        return "Flush";
    if (check5(cards, switchedCards))
        return "Straight";
    if (check6(cards, switchedCards))
        return "Three of a Kind";
    if (check7(cards, switchedCards))
        return "Two Pair";
    if (check8(cards, switchedCards))
        return "One Pair";
    return "High Card";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string type;
    vector<pair<string, string>> cardsRaw;

    while (cin >> type) {
        if (type == "parse") {
            cout << parse(cardsRaw) << endl;
            cardsRaw.clear();
            continue;
        }

        string numberStr;
        cin >> numberStr;
        cardsRaw.emplace_back(type, numberStr);
    }
}
