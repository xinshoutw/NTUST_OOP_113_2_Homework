#include <iostream>
#include <string>

int main() {
    std::string number_1[10] = {" _ ", "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ "};
    std::string number_2[10] = {"| |", "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|"};
    std::string number_3[10] = {"|_|", "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|"};

    std::string input;
    while (getline(std::cin, input)) {
        for (const auto& i : input) {
            if (!isdigit(i))
                continue;
            std::cout << number_1[i - '0'];
        }
        std::cout << '\n';

        for (const auto& i : input) {
            if (!isdigit(i))
                continue;
            std::cout << number_2[i - '0'];
        }
        std::cout << '\n';

        for (const auto& i : input) {
            if (!isdigit(i))
                continue;
            std::cout << number_3[i - '0'];
        }
        std::cout << '\n';
    }

    return 0;
}