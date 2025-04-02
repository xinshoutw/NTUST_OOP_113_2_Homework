#include "Polynomial.h"

int Polynomial::mySize() const {
    for (int i = static_cast<int>(coeff.size()) - 1; i >= 0; --i) {
        if (coeff[i] != 0) {
            return i + 1;
        }
    }

    return 0;
}

double Polynomial::operator[](const int index) const {
    if (index >= mySize()) {
        return 0.0;
    }

    return this->coeff[index];
}

double& Polynomial::operator[](const int index) {
    if (index >= mySize()) {
        std::valarray<double> newCoeff(0.0, index + 1);
        std::copy(std::begin(coeff), std::end(coeff), std::begin(newCoeff));
        coeff = std::move(newCoeff);
    }

    return this->coeff[index];
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    if (mySize() >= rhs.mySize())
        return Polynomial(coeff + rhs.coeff);
    return Polynomial(rhs.coeff + coeff);
}

Polynomial Polynomial::operator+(const double rhs) const {
    if (mySize() < 1) {
        return Polynomial(std::valarray<double>{rhs});
    }

    auto newCoeff = coeff;
    newCoeff[0] += rhs;
    return Polynomial(std::move(newCoeff));
}

Polynomial operator+(const double lhs, const Polynomial& rhs) {
    return rhs + lhs;
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    if (mySize() >= rhs.mySize())
        return Polynomial(coeff - rhs.coeff);
    return Polynomial(-(rhs.coeff - coeff));
}

Polynomial Polynomial::operator-(const double rhs) const {
    if (mySize() < 1) {
        return Polynomial(std::valarray<double>{-rhs});
    }

    auto newCoeff = coeff;
    newCoeff[0] -= rhs;
    return Polynomial(std::move(newCoeff));
}

Polynomial operator-(const double lhs, const Polynomial& rhs) {
    return rhs * (-1) + lhs;
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    std::valarray<double> newCoeff(mySize() + rhs.mySize());

    for (int m = 0; m < mySize(); m++) {
        for (int n = 0; n < rhs.mySize(); n++) {
            newCoeff[m + n] += coeff[m] * rhs[n];
        }
    }

    return Polynomial(std::move(newCoeff));
}

Polynomial Polynomial::operator*(const double rhs) const {
    if (mySize() < 1) {
        return Polynomial{};
    }

    return Polynomial(coeff * rhs);
}

Polynomial& Polynomial::operator=(const Polynomial& rhs) {
    if (this != &rhs) {
        this->coeff = rhs.coeff;
    }

    return *this;
}

Polynomial operator*(const double lhs, const Polynomial& rhs) {
    return rhs * lhs;
}

double evaluate(const Polynomial& poly, const double var) {
    double result = 0;
    for (int i = 0; i < poly.mySize(); ++i) {
        result += poly[i] * pow(var, i);
    }

    return result;
}