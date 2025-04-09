#ifndef PRIMENUMBER_H
#define PRIMENUMBER_H

class PrimeNumber {
public:
    int value;
    int get() const;
    PrimeNumber()
        : value(1) {}
    explicit PrimeNumber(const int _value)
        : value(_value) {}
    PrimeNumber& operator++();
    PrimeNumber operator++(int);
    PrimeNumber& operator--();
    PrimeNumber operator--(int);
};

#endif // PRIMENUMBER_H
