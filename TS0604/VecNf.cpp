#include "VecNf.h"
#include <iostream>

VecNf::VecNf()
    : cnt(1) {
    vec.resize(1, 0);
}

VecNf::VecNf(const float* dest, const int cnt) {
    vec = std::valarray<float>(dest, cnt);
    this->cnt = cnt;
}

VecNf::VecNf(std::valarray<float>&& dest, const int cnt) {
    this->vec = dest;
    this->cnt = cnt;
}

VecNf::VecNf(const VecNf& rhs) {
    this->vec = rhs.vec;
    this->cnt = rhs.cnt;
}

int VecNf::Size() const {
    return cnt;
}

float VecNf::operator[](const size_t index) const {
    return this->vec[index];
}

float& VecNf::operator[](const size_t index) {
    return this->vec[index];
}

VecNf& VecNf::operator=(const VecNf& rhs) {
    std::cout << "ASSIGNMENT!!!\n";
    this->vec = rhs.vec;
    this->cnt = rhs.cnt;

    return *this;
}

VecNf VecNf::operator+(const VecNf& rhs) {
    if (this->cnt != rhs.cnt) {
        std::cout << "dimensions inconsistent\n";
        return {};
    }

    auto newVec = VecNf(*this);
    newVec.vec += rhs.vec;
    return newVec;
}

VecNf VecNf::operator-(const VecNf& rhs) {
    if (this->cnt != rhs.cnt) {
        std::cout << "dimensions inconsistent\n";
        return {};
    }

    auto newVec = VecNf(*this);
    newVec.vec -= rhs.vec;
    return newVec;
}

double VecNf::operator*(const VecNf& rhs) const {
    if (this->cnt != rhs.cnt) {
        std::cout << "dimensions inconsistent\n";
        return 0;
    }

    return (this->vec * rhs.vec).sum();
}
VecNf VecNf::operator*(const float scale) {
    auto newVec = VecNf(*this);
    newVec.vec *= scale;

    return newVec;
}
VecNf operator*(const float scale, const VecNf& rhs) {
    return VecNf(rhs.vec * scale, rhs.cnt);
}
