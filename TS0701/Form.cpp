#include "Form.h"
#include <algorithm>
#include <iostream>

void Form::SetFileName(string fileName) {
    this->fileName = fileName;
}

void Form::SetInputWord(string inputWord) {
    this->inputWord = inputWord;
}

void Form::ProcessInputWord() {

    for (const auto& i : inputWord) {
        if (tolower(i) < 'a' || tolower(i) > 'z')
            continue;
        this->inputWordAppearCount[tolower(i) - 'a']++;
    }
}

void Form::Load_CompareWord() {
    freopen(this->fileName.c_str(), "r", stdin);

    string line;
    while (cin >> line) {
        int inputCopy[26] = {0};
        bool failed = false;
        copy_n(inputWordAppearCount, 26, inputCopy);

        for (const auto& i : line) {
            if (tolower(i) < 'a' || tolower(i) > 'z')
                continue;

            if (inputCopy[tolower(i) - 'a'] == 0) {
                failed = true;
                break;
            }

            inputCopy[tolower(i) - 'a']--;
        }

        if (!failed) {
            validWords.push_back(line);
        }
    }
}

void Form::PrintFoundWords() {
    for (const auto& i : this->validWords) {
        cout << i << '\n';
    }
}