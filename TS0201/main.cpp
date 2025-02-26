#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
T calculateAverage(const std::vector<T>& vec) {
    const size_t vecSize = std::size(vec); // available in C++17
    auto total = std::accumulate(vec.begin(), vec.end(), 0.0);
    return total / vecSize;
}


template <typename T>
T calculateStandardDeviation(const std::vector<T>& vec, const T& average) {
    const size_t vecSize = std::size(vec); // available in C++17
    if (vecSize <= 1) {
        return 0.0;
    }

    auto varianceFunc = [&average](T accumulator, const T& val) {
        return accumulator + (val - average) * (val - average);
    };

    return sqrt(std::accumulate(vec.begin(), vec.end(), 0.0, varianceFunc) / vecSize);
}

std::pair<double, double> compute(const std::vector<double>& inputVec) {
    const auto inputAverage = calculateAverage<double>(inputVec);
    const auto standardDeviation = calculateStandardDeviation<double>(inputVec, inputAverage);

    return {inputAverage, standardDeviation};
}

int main() {
    int inputCount = 0;

    while (std::cin >> inputCount) {
        std::vector<double> inputVec(inputCount);

        for (size_t i = 0; i < inputCount; ++i) {
            std::cin >> inputVec[i];
        }

        const auto result = compute(inputVec);

        printf("Average:%g\tStandard deviation:%g\n", result.first, result.second);
    }
}
