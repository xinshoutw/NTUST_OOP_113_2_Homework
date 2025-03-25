#include "Atoi.h"

Atoi::Atoi() {
    this->beTrans = "";
}

Atoi::Atoi(string s) {
    this->beTrans = s;
}

void Atoi::SetString(string s) {
    this->beTrans = s;
}

const string Atoi::GetString() {
    return this->beTrans;
}

int Atoi::Length() {
    return static_cast<int>(this->beTrans.size()) - (beTrans[0] == '-' ? 1 : 0);
}

bool Atoi::IsDigital() {
    return all_of(this->beTrans.begin(), this->beTrans.end(), [](const auto& i) {
        return isdigit(i) || i == '-';
    });
}

int Atoi::StringToInteger() {
    return stoi(beTrans);

    int result = 0;
    for (int i = 0; i < (int)beTrans.size(); ++i) {
        result += beTrans[(int)beTrans.size() - 1] * pow(10, i);
    }

    return result;
}
