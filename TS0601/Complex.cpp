#include "Complex.h"
#include <sstream>

double Complex::real() const {
    return realValue;
}

double Complex::imag() const {
    return imaginaryValue;
}

double Complex::norm() const {
    return sqrt(realValue * realValue + imaginaryValue * imaginaryValue);
}

Complex Complex::operator+(const Complex c) const {
    return {realValue + c.realValue, imaginaryValue + c.imaginaryValue};
}

Complex Complex::operator-(const Complex c) const {
    return {realValue - c.realValue, imaginaryValue - c.imaginaryValue};
}

Complex Complex::operator*(const Complex c) const {
    return {realValue * c.realValue - imaginaryValue * c.imaginaryValue, imaginaryValue * c.realValue + c.imaginaryValue * realValue};
}

Complex Complex::operator/(const Complex c) const {
    const double div = c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue;
    return (*this) * Complex(c.realValue / div, -c.imaginaryValue / div);
}

double real(const Complex c) {
    return c.realValue;
}

double imag(const Complex c) {
    return c.imaginaryValue;
}

double norm(const Complex c) {
    return sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
}

Complex operator+(const double d, const Complex c) {
    return Complex(d) + c;
}

Complex operator-(const double d, const Complex c) {
    return Complex(d) - c;
}

Complex operator*(const double d, const Complex c) {
    return Complex(d) * c;
}

Complex operator/(const double d, const Complex c) {
    return Complex(d) / c;
}

bool operator==(const Complex c1, const Complex c2) {
    return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}

ostream& operator<<(ostream& strm, const Complex& c) {
    strm << c.realValue << " + " << c.imaginaryValue << "*i";
    return strm;
}

istream& operator>>(istream& strm, Complex& c) {
    std::string inp;
    char foo;
    strm >> std::ws;
    getline(strm, inp);
    sscanf(inp.c_str(), "%c = %lf + %lf*i", &foo, &(c.realValue), &(c.imaginaryValue));
    return strm;
}
