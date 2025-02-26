#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>

// check whether string only have digit number.
// return true for success
bool is_digits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

struct BigInt {
    // split string to uint64_t number blocks
    static constexpr int BASE_DIGITS = 18; // log10(UINT64_MAX) is approximately 18
    static constexpr uint64_t BASE = 1000000000000000000ULL; // 10^18
    // blocks[0] is the lowest block
    std::vector<uint64_t> blocks;

    // construct BigInt from string (split into blocks from right to left, each block has at most BASE_DIGITS digits)
    explicit BigInt(const std::string& s) {
        // to remove prefix  0
        std::string str = s;
        str.erase(0, str.find_first_not_of('0'));
        if (str.empty()) str = "0";

        // Start from the right side of the string, take BASE_DIGITS digits each time
        for (int i = static_cast<int>(str.size()); i > 0; i -= BASE_DIGITS) {
            const int start = std::max(0, i - BASE_DIGITS);
            const int len = i - start;
            blocks.push_back(std::stoull(str.substr(start, len)));
        }
    }

    // construct by number
    explicit BigInt(uint64_t x = 0) {
        if (x == 0) {
            blocks.push_back(0);
            return;
        }

        while (x) {
            blocks.push_back(x % BASE);
            x /= BASE;
        }
    }

    // BigNumber to string
    [[nodiscard]] std::string toString() const {
        std::string s = std::to_string(blocks.back());

        // add leading zeros
        for (int i = static_cast<int>(blocks.size()) - 2; i >= 0; --i) {
            std::string blockStr = std::to_string(blocks[i]);
            s += std::string(BASE_DIGITS - blockStr.size(), '0') + blockStr;
        }
        return s;
    }
};

BigInt Add(const BigInt& lhs, const BigInt& rhs) {
    BigInt result(0);
    result.blocks.clear();

    uint64_t carry = 0;
    const size_t n = std::max(lhs.blocks.size(), rhs.blocks.size());
    for (size_t i = 0; i < n || carry; i++) {
        // calculate sum
        const uint64_t a = (i < lhs.blocks.size() ? lhs.blocks[i] : 0);
        const uint64_t b = (i < rhs.blocks.size() ? rhs.blocks[i] : 0);
        uint64_t sum = a + b + carry;

        // calculate leak number
        carry = (sum >= BigInt::BASE) ? 1 : 0;
        if (carry)
            sum -= BigInt::BASE;

        // push to result
        result.blocks.push_back(sum);
    }

    return result;
}

int main() {
    int32_t inputCounts;
    std::string inputL, inputR;

    while (std::cin >> inputCounts) {
        for (int i = 0; i < inputCounts; i++) {
            std::cin >> inputL >> inputR;
            if (!is_digits(inputL) || !is_digits(inputR)) {
                std::cout << "Not a valid number, please try again.\n";
                continue;
            }

            BigInt bigL(inputL);
            BigInt bigR(inputR);
            BigInt sum = Add(bigL, bigR);

            std::cout << sum.toString() << std::endl;
        }
    }

    return 0;
}
