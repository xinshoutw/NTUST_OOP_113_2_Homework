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
};

#endif // Fraction_H