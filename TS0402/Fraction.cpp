#include "Fraction.h"

void Fraction::setNumerator(const int nu) {
    this->numerator = nu;
}

void Fraction::setDenominator(const int de) {
    this->denominator = de;
}

void Fraction::getDouble() const {
    if (numerator % denominator == 0) {
        std::cout << numerator / denominator << '\n';
    } else {
        std::cout << std::setprecision(6) << std::fixed << static_cast<double>(numerator) / denominator << '\n';
    }
}

void Fraction::outputReducedFraction() const {
    if (numerator % denominator == 0) {
        std::cout << numerator / denominator << '\n';
    }
    else {
        const int32_t gcd_number = GCD(numerator, denominator);
        std::cout << numerator / gcd_number << '/' << denominator / gcd_number << '\n';
    }
}

int32_t Fraction::GCD(int32_t a, int32_t b) {
    int32_t r;
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}