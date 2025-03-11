#ifndef Fraction_H
#define Fraction_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    void setNumerator(int nu);
    void setDenominator(int de);
    void getDouble() const;
    void outputReducedFraction() const;
    static int32_t GCD(int32_t a, int32_t b);
};

#endif // Fraction_H