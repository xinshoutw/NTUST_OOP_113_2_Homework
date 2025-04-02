#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <valarray>

class Polynomial {

private:
    std::valarray<double> coeff;

public:
    Polynomial() = default;

    Polynomial(double* coeff, int size)
        : coeff(coeff, size) {}

    Polynomial(const Polynomial& poly)
        : coeff(poly.coeff) {}

    explicit Polynomial(std::valarray<double>&& coeff)
        : coeff(std::move(coeff)) {}

    ~Polynomial() = default;

    [[nodiscard]] int mySize() const;

    double operator[](int index) const;
    double& operator[](int index);

    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator+(double rhs) const;
    friend Polynomial operator+(double lhs, const Polynomial& rhs);

    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator-(double rhs) const;
    friend Polynomial operator-(double lhs, const Polynomial& rhs);

    Polynomial operator*(const Polynomial& rhs) const;
    Polynomial operator*(double rhs) const;
    friend Polynomial operator*(double lhs, const Polynomial& rhs);

    Polynomial& operator=(const Polynomial& rhs);

    friend double evaluate(const Polynomial& poly, double var);
};

#endif // POLYNOMIAL_H
