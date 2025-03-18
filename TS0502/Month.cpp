#include "Month.h"

std::map<std::string, int> Month::month2Int = {
    {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12},
};

std::string Month::int2Month[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Month::Month() {
    this->month = 1;
}

Month::Month(const char first, const char second, const char third) {
    const auto combined_input_str = new char[4];
    combined_input_str[0] = first;
    combined_input_str[1] = second;
    combined_input_str[2] = third;
    combined_input_str[3] = '\0';

    const auto found = Month::month2Int.find(combined_input_str);

    if (found == Month::month2Int.end()) {
        this->month = 1;
    } else {
        this->month = found->second;
    }
}

Month::Month(const int monthInt) {
    if (monthInt < 1 || monthInt > 12) {
        this->month = 1;
        return;
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

    const auto found = Month::month2Int.find(combined_input_str);

    if (found == Month::month2Int.end()) {
        this->month = 1;
    } else {
        this->month = found->second;
    }
}

void Month::outputInt() const {
    std::cout << this->month;
}

void Month::outputStr() const {
    std::cout << Month::int2Month[this->month];
}

Month Month::nextMonth() const {
    return Month(this->month + 1);
}
