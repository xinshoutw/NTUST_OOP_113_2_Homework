////////////////////////////////////////////////////////////////////////////////
/// @brief Calculate the sum of two BigNumbers.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Stored by uint64_t blocks.
 */
struct BigInt {
    // log10(UINT64_MAX) is approximately 18
    static constexpr int BASE_DIGITS = 18;

    // 10^18
    static constexpr uint64_t BASE = 1000000000000000000ULL;

    // note: blocks[0] is the lowest block
    std::vector<uint64_t> blocks;

    /**
     * @brief Construct BigInt from string
     *        (split into blocks from right to left, each block has at most BASE_DIGITS digits).
     * @param str input string
     */
    explicit BigInt(std::string&& str);

    /**
     * @brief Construct BigInt from number.
     * @param num input number
     */
    explicit BigInt(uint64_t num = 0);

    /**
     * @brief convert BigNumber blocks to string
     * @return
     */
    std::string to_string() const;
};

/**
 * @brief Check whether a string only include digit number.
 * @param str input string
 * @return true for all are digits
 */
bool Is_Digits(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

/**
 * @brief Calculate the sum of two numbers.
 * @param lhs left-hand side number
 * @param rhs right-hand side number
 * @return sum of numbers
 */
BigInt Add(const BigInt& lhs, const BigInt& rhs) {
    BigInt result(0);
    result.blocks.clear();

    uint64_t carry = 0;
    const size_t max_block_size = std::max(lhs.blocks.size(), rhs.blocks.size());
    for (size_t i = 0; i < max_block_size || carry; i++) {
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
    int32_t input_counts;
    std::string input_string_l, input_string_r;

    while (std::cin >> input_counts) {
        for (int i = 0; i < input_counts; i++) {
            std::cin >> input_string_l >> input_string_r;
            if (!Is_Digits(input_string_l) || !Is_Digits(input_string_r)) {
                std::cout << "Not a valid number, please try again.\n";
                continue;
            }

            BigInt big_l(std::move(input_string_l));
            BigInt big_r(std::move(input_string_r));
            BigInt sum = Add(big_l, big_r);

            std::cout << sum.to_string() << std::endl;
        }
    }

    return 0;
}

////////////////////////////////////////
/// Implements
////////////////////////////////////////
BigInt::BigInt(std::string&& str) {
    str.erase(0, str.find_first_not_of('0'));

    if (str.empty())
        str = "0";

    // Start from the right side of the string, take BASE_DIGITS digits each time
    for (int i = static_cast<int>(str.size()); i > 0; i -= BASE_DIGITS) {
        // use "max" method to avoid getting negative number
        const int start_index = std::max(0, i - BASE_DIGITS);
        const int new_str_len = i - start_index;
        blocks.push_back(std::stoull(str.substr(start_index, new_str_len)));
    }
}

BigInt::BigInt(uint64_t num) {
    if (num == 0) {
        blocks.push_back(0);
        return;
    }

    while (num) {
        blocks.push_back(num % BASE);
        num /= BASE;
    }
}
std::string BigInt::to_string() const {
    // add last(lowest) block
    std::string result = std::to_string(blocks.back());

    // add other blocks
    for (int i = static_cast<int>(blocks.size()) - 2; i >= 0; --i) {
        std::string block_str = std::to_string(blocks[i]);
        result += std::string(BASE_DIGITS - block_str.size(), '0') + block_str;
    }

    return result;
}