#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

class Calculator {
public:
    static string add(string lhs, string rhs) {
        bool negative = false;
        if (lhs.front() == '-' && rhs.front() == '-') {
            lhs.erase(0, 1);
            rhs.erase(0, 1);
            negative = true;
        } else if (lhs.front() == '-') {
            lhs.erase(0, 1);
            return sub(rhs, lhs);
        } else if (rhs.front() == '-') {
            rhs.erase(0, 1);
            return sub(lhs, rhs);
        }

        const int maxLength = max(static_cast<int>(lhs.length()), static_cast<int>(rhs.length()));
        const int minLength = min(static_cast<int>(lhs.length()), static_cast<int>(rhs.length()));

        string reverse_lhs(lhs.rbegin(), lhs.rend());
        reverse_lhs.resize(maxLength, '0');

        string reverse_rhs(rhs.rbegin(), rhs.rend());
        reverse_rhs.resize(maxLength, '0');

        string result;
        result.reserve(maxLength + 1);
        bool carry = false;

        for (int i = 0; i < maxLength; ++i) {
            const int tmp = (reverse_lhs[i] - '0') + (reverse_rhs[i] - '0') + carry;
            result += static_cast<char>((tmp % 10) + '0');
            carry = (tmp >= 10);
        }

        if (carry) {
            result += '1';
        }

        if (negative && result != "0") {
            result += '-';
        }

        reverse(result.begin(), result.end());
        return result;
    }

    static string sub(string lhs, string rhs) {
        if (lhs.front() == '-' && rhs.front() == '-') {
            // (-a) - (-b)  =>  b - a
            lhs.erase(0, 1);
            rhs.erase(0, 1);
            return sub(rhs, lhs);
        }

        if (lhs.front() == '-') {
            // (-a) - b  =>  (-a) + (-b)
            return add(move(lhs), '-' + rhs);
        }

        if (rhs.front() == '-') {
            // a - (-b)  =>  a + b
            rhs.erase(0, 1);
            return add(lhs, rhs);
        }

        bool negative = false;
        if (rhs.size() > lhs.size() || (rhs.size() == lhs.size() && rhs > lhs)) {
            swap(rhs, lhs);
            negative ^= 1;
        }

        const int maxLength = max(static_cast<int>(lhs.length()), static_cast<int>(rhs.length()));
        const int minLength = min(static_cast<int>(lhs.length()), static_cast<int>(rhs.length()));

        // lhs - rhs
        string reverse_lhs;
        reverse_lhs.resize(maxLength, '0');
        reverse_copy(lhs.begin(), lhs.end(), reverse_lhs.begin());

        string reverse_rhs;
        reverse_rhs.resize(maxLength, '0');
        reverse_copy(rhs.begin(), rhs.end(), reverse_rhs.begin());

        string result;
        result.reserve(maxLength + 1);
        bool carry = false;

        for (int i = 0; i < maxLength; ++i) {
            const int tmp = reverse_lhs[i] - reverse_rhs[i] - carry;
            if (tmp < 0) {
                result += static_cast<char>((10 + tmp) + '0');
                carry = true;
            } else {
                result += static_cast<char>(tmp + '0');
                carry = false;
            }
        }

        fixReversedNumber(result);
        reverse(result.begin(), result.end());
        return result;
    }

    static string mul(string lhs, string rhs) {
        const bool negative = (lhs.front() == '-') ^ (rhs.front() == '-');

        if (lhs.front() == '-')
            lhs.erase(0, 1);
        if (rhs.front() == '-')
            rhs.erase(0, 1);

        if (lhs == "0" || rhs == "0") {
            return "0";
        }

        string result = "0";
        for (int i = 0; i < rhs.length(); ++i) {
            string partial = singleMul(lhs, *(rhs.end() - 1 - i) - '0');
            partial.insert(partial.end(), i, '0');
            result = add(result, partial);
        }

        if (negative) {
            result.insert(result.begin(), '-');
        }

        return result;
    }

    static void fixReversedNumber(string& num) {
        // remove redundant '-'
        bool negative = false;
        while (num.back() == '-') {
            negative ^= 1;
            num.pop_back();
        }

        while (num.back() == '0') {
            num.pop_back();
        }

        if (num.empty()) {
            num.push_back('0');
            return;
        }

        if (negative) {
            num.push_back('-');
        }
    }

    static string singleMul(const string& inp, int singleNum) {
        if (singleNum == 0)
            return "0";

        string result;
        result.reserve(inp.size() + 1);
        int carry = 0;

        for (int i = inp.length() - 1; i >= 0; --i) {
            int tmp = (inp[i] - '0') * singleNum + carry;
            result.insert(result.begin(), static_cast<char>((tmp % 10) + '0'));
            carry = tmp / 10;
        }
        if (carry) {
            result.insert(result.begin(), static_cast<char>(carry + '0'));
        }

        return result;
    }
};

int main() {
    string lhs, rhs;
    // cout << Calculator::singleMul("123", 2);
    // cout << Calculator::singleMul("1230", 2);
    while (cin >> lhs >> rhs) {
        cout << Calculator::add(lhs, rhs) << '\n';
        cout << Calculator::sub(lhs, rhs) << '\n';
        cout << Calculator::mul(lhs, rhs) << '\n';
    }
}
