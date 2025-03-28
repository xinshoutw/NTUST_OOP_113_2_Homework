#include "Point.h"
#include <algorithm>

void Point::Set(const float x, const float y) {
    this->x = x;
    this->y = y;
}

void Point::Move(const float dx, const float dy) {
    this->x += dx;
    this->y += dy;
}

void Point::Rotate() {
    std::swap(this->x, this->y);
    this->y *= -1;
}

void Point::Reflect() {
    this->x *= -1;
    this->y *= -1;
}

float Point::GetHorizontal() const {
    if (this->x == 0)

        return 0;
    return this->x;
}

float Point::GetVertical() const {
    if (this->y == 0)
        return 0;

    return this->y;
}