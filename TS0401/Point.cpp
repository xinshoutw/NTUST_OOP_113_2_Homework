#include "Point.h"

void Point::Set(const int vertical, const int horizontal) {
    this->vertical = vertical;
    this->horizontal = horizontal;
}

void Point::Move(const int x, const int y) {
    vertical += x;
    horizontal += y;
}

void Point::Rotate() {
    std::swap(vertical, horizontal);
    horizontal = ~horizontal + 1;
}
