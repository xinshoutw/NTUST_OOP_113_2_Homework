#include "Month.h"

std::map<std::string, int> Month::month2Int = {
    {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12},
};

std::string Month::int2Month[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Month::Month() {
    this->month = 1;
}

Month::Month(char first, char second, char third) {
    const auto combined_input_str = new char[4];
    combined_input_str[0] = first;
    combined_input_str[1] = second;
    combined_input_str[2] = third;

    this->month = Month::month2Int[combined_input_str];
}

Month::Month(const int monthInt) {
    if (monthInt < 1 || monthInt > 12) {
        this->month = 1;
    }

    this->month = monthInt;
}

Month::~Month() = default;

void Month::inputInt() {
    int input_int;
    std::cin >> input_int;

    if (input_int < 1 || input_int > 12) {
        this->month = 1;
    }

    this->month = input_int;
}

void Month::inputStr() {
    const auto combined_input_str = new char[4];
    std::cin >> combined_input_str[0];
    std::cin >> combined_input_str[1];
    std::cin >> combined_input_str[2];

    this->month = Month::month2Int[combined_input_str];
}

void Month::outputInt() {
    std::cout << this->month;
}

void Month::outputStr() {
    std::cout << Month::int2Month[this->month];
}

Month Month::nextMonth() {
    return Month{this->month + 1};
}
