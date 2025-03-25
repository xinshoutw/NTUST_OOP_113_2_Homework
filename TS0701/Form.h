#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

using namespace std;
class Form {
private:
    string fileName;
    string inputWord;
    int inputWordAppearCount[26] = {0};
    vector<string> validWords;

public:
    Form() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    void SetInputWord(string inputWord); // set input
    void ProcessInputWord();             // process input
    void SetFileName(string fileName);   // set file name
    void Load_CompareWord();             // read-in data and compare
    void PrintFoundWords();              // print answers
};
#endif // FORM_H