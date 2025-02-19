#include <iostream>

int main() {
    constexpr double PI = 3.14159265358979323846;
    double input_radius;
    std::cout.precision(6);
    while (std::cin >> input_radius) {
        std::cout << std::fixed << input_radius * input_radius * input_radius * PI * 4 / 3 << std::endl;
    }

    return 0;
}
