#include "NumberGame.h"
#include <iostream>

void NumberGame::SetInput(int32_t inp) {
    this->inp = inp;
}

void NumberGame::ProcessInput() {
    while (inp > 0) {
        const int cur = inp % 10;
        inp /= 10;

        std::unordered_set<int> newValues;

        for (const auto& value : possibles) {
            newValues.insert(value * cur);
        }

        possibles.insert(cur);
        possibles.insert(newValues.begin(), newValues.end());
    }
}

void NumberGame::SetFileName(const char* fileName) {
    this->fileName = fileName;
};

void NumberGame::LoadNumberList() {
    freopen(fileName, "r", stdin);
    std::cin.clear();

    int32_t word;
    while (std::cin >> word) {
        if (possibles.find(word) != possibles.end()) {
            founds.push_back(word);
        }
    }

    fclose(stdin);
}

void NumberGame::PrintAllValid() const {
    for (const auto& i : founds) {
        std::cout << i << '\n';
    }
}

void NumberGame::Reset() {
    this->possibles.clear();
    this->founds.clear();
}