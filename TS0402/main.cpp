////////////////////////////////////////////////////////////////////////////////
/// @brief Define a class named "Fraction", implement the following methods.
///        1. two private integer variables named "numerator" and "denominator"
///        2. "setNumerator" public method with one parameter to reset member variable
///        3. "setDenominator" public method with one parameter to reset member variable
///        4. "getDouble" public method to print the divided result with no tailing zeros
///        5. "outputReducedFraction" public method to print the simplest expression
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "Fraction.h"

int main() {
    Fraction f1, f2;
    f1.setNumerator(4);
    f1.setDenominator(2);
    f1.getDouble();
    f1.outputReducedFraction();

    f2.setNumerator(20);
    f2.setDenominator(60);
    f2.getDouble();
    f2.outputReducedFraction();
    return 0;
}
