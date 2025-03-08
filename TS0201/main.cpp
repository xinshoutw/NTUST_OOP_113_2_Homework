////////////////////////////////////////////////////////////////////////////////
/// @brief BRIEF
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <numeric>
#include <vector>

/**
 * @brief Calculate the average value.
 * @param number_vector numbers in vector
 * @return average number
 */
double CalculateAverage(const std::vector<double>& number_vector) {
    const auto vec_size = static_cast<uint32_t>(number_vector.size());
    const auto total = std::accumulate(number_vector.begin(), number_vector.end(), 0.0);
    return total / vec_size;
}

/**
 * @brief Calculate the standard deviation.
 * @param number_vector numbers in vector
 * @param vector_average average value of number_vector
 * @return standard deviation
 */
double CalculateStandardDeviation(const std::vector<double>& number_vector, const double vector_average) {
    const auto vec_size = static_cast<uint32_t>(number_vector.size());
    if (vec_size <= 1) {
        return 0.0;
    }

    auto variance_func = [&vector_average](const double accumulator, const double val) {
        return accumulator + (val - vector_average) * (val - vector_average);
    };

    const double squared_sum = std::accumulate(number_vector.begin(), number_vector.end(), 0.0, variance_func);

    return sqrt(squared_sum / vec_size);
}

std::pair<double, double> compute(const std::vector<double>& input_vector) {
    const double input_average = CalculateAverage(input_vector);
    const double standard_deviation = CalculateStandardDeviation(input_vector, input_average);

    return {input_average, standard_deviation};
}

int main() {
    int input_count = 0;

    // read until EOF
    while (std::cin >> input_count) {
        std::vector<double> input_vec(input_count);

        // read each input number and assign in vector
        for (size_t i = 0; i < input_count; ++i) {
            std::cin >> input_vec[i];
        }

        const std::pair<double, double> result = compute(input_vec);
        printf("Average:%g\tStandard deviation:%g\n", result.first, result.second);
    }

    return 0;
}
