#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
public:
    double realValue, imaginaryValue;

    Complex()
        : realValue(0)
        , imaginaryValue(0) {}
    //~Complex();
    explicit Complex(const double r)
        : realValue(r)
        , imaginaryValue(0) {}
    //~Complex(double r);
    Complex(const double r, const double i)
        : realValue(r)
        , imaginaryValue(i) {}
    //~Complex(double r, double i);
    double real() const;
    double imag() const;
    double norm() const;
    friend double real(Complex c);
    friend double imag(Complex c);
    friend double norm(Complex c);
    Complex operator+(Complex c) const;
    Complex operator-(Complex c) const;
    Complex operator*(Complex c) const;
    Complex operator/(Complex c) const;
    friend Complex operator+(double d, Complex c);
    friend Complex operator-(double d, Complex c);
    friend Complex operator*(double d, Complex c);
    friend Complex operator/(double d, Complex c);
    friend bool operator==(Complex c1, Complex c2);
    friend ostream& operator<<(ostream& strm, const Complex& c);
    friend istream& operator>>(istream& strm, Complex& c);
};

#endif // COMPLEX_H
