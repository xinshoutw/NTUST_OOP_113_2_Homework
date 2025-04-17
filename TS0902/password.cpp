#include "password.h"
#include <algorithm>
#include <iostream>

namespace {
std::string password;

bool isValid() {
    return password.length() >= 8 && std::any_of(password.begin(), password.end(), [](char ch) {
               return !std::isalpha(ch);
           });
}
} // namespace

namespace Authenticate {
void inputPassword() {
    do {
        std::cout << "Enter your password (at least 8 characters " << "and at least one non-letter)" << std::endl;
        std::cin >> password;
    } while (!isValid());
}

std::string getPassword() {
    return password;
}
} // namespace Authenticate
