#include "Form.h"
#include <iostream>

void Form::SetInputWord(string inputWord) {
	this->inputWord = inputWord;
}

void Form::ProcessInputWord() {
	for (const char& i : this->inputWord) {
		this->inputWords[tolower(i) - 'a']++;
	}
}

void Form::SetFileName(string fileName) {
	this->fileName = fileName;
}

void Form::Load_CompareWord() {
	freopen(this->fileName.c_str(), "r", stdin);

	string line;
	while (cin >> line) {
		int copy[26];
		copy_n(this->inputWords, 26, copy);

		bool errFlag = false;
		for (const char& i: line) {
			if (--copy[tolower(i) - 'a'] < 0) {
				errFlag = true;
				break;
			}
		}

		if (!errFlag) {
			this->foundWords.push_back(line);
		}
	}

}

void Form::PrintFoundWords() {
	for (const string& i: this->foundWords) {
		cout << i << '\n';
	}
}