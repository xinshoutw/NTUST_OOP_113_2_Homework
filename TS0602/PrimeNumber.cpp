#include "PrimeNumber.h"

int PrimeNumber::get() const {
    return value;
}

PrimeNumber& PrimeNumber::operator++() {
    value =
        value == 1 ? 2 :
        value == 2 ? 3 :
        value == 3 ? 5 :
        value == 5 ? 7 :
        value == 7 ? 11 :
        value == 11 ? 13 :
        value == 13 ? 17 :
        -1;

    return *this;
}

PrimeNumber PrimeNumber::operator++(int) {
    const PrimeNumber cp(value);
    ++(*this);
    return cp;
}

PrimeNumber& PrimeNumber::operator--() {
    value =
        value == 2 ? 1 :
        value == 3 ? 2 :
        value == 5 ? 3 :
        value == 7 ? 5 :
        value == 11 ? 7 :
        value == 13 ? 11 :
        value == 17 ? 13 :
        -1;

    return *this;
}

PrimeNumber PrimeNumber::operator--(int) {
    const PrimeNumber cp(value);
    --(*this);
    return cp;
}
