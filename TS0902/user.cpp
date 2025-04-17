#include "user.h"
#include <algorithm>
#include <iostream>

namespace {
std::string username;

bool isValid() {
    return username.length() == 8 && std::all_of(username.begin(), username.end(), [](char ch) {
               return std::isalpha(ch);
           });
}
} // namespace

namespace Authenticate {
void inputUserName() {
    do {
        std::cout << "Enter your username (8 letters only)" << std::endl;
        std::cin >> username;
    } while (!isValid());
}

std::string getUserName() {
    return username;
}
} // namespace Authenticate