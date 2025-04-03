#pragma once

#include <valarray>

class VecNf {
public:
    VecNf();
    VecNf(const float* dest, int cnt);
    VecNf(std::valarray<float>&& dest, int cnt);
    VecNf(const VecNf& rhs);

    int Size() const;

    float operator[](size_t index) const;
    float& operator[](size_t index);

    VecNf& operator=(const VecNf& rhs);

    VecNf operator+(const VecNf& rhs);
    friend VecNf operator+(const VecNf& lhs, const VecNf& rhs);

    VecNf operator-(const VecNf& rhs);
    friend VecNf operator-(const VecNf& lhs, const VecNf& rhs);

    double operator*(const VecNf& rhs) const;
    VecNf operator*(float scale);
    friend VecNf operator*(float scale, const VecNf& rhs);

private:
    std::valarray<float> vec;
    int cnt;
};