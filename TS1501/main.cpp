#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> names;
    std::string name;
    freopen("name.txt", "r", stdin);
    while (std::getline(std::cin, name)) {
        names.insert(name);
    }

    for (const std::string& i : names) {
        std::cout << i << '\n';
    }
}