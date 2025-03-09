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
        std::cout << static_cast<double>(numerator) / denominator << '\n';
    }
}

void Fraction::outputReducedFraction() const {
    if (numerator % denominator == 0) {
        std::cout << numerator / denominator << '\n';
    } else {
        const int32_t gcd_number = std::__algo_gcd(numerator, denominator);
        std::cout << numerator / gcd_number << '/' << denominator / gcd_number << '\n';
    }
}
