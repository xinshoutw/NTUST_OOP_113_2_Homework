#ifndef TEMPLATE_H
#define TEMPLATE_H

template <typename T>
double absoluteValue(T lhs, T rhs) {
    if (lhs < rhs) {
        return rhs - lhs;
    }
    return lhs - rhs;
}

#endif // TEMPLATE_H
