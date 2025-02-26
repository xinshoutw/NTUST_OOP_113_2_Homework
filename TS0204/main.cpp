#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

struct Employee {
    std::string name;
    int32_t salary{};
    int32_t award{};

    explicit Employee(std::string name = "", const int32_t salary = -1, const int32_t award = -1) :
        name(std::move(name)),
        salary(salary),
        award(award) {
    }
};

int main() {
    int32_t inputCounts;

    std::string inputName;
    int32_t inputSalary;
    int32_t inputAward;

    while (std::cin >> inputCounts) {
        std::vector<Employee> employees(inputCounts);

        int32_t maxNameLength = 0;
        int32_t maxSalaryLength = 0;
        int32_t maxAwardLength = 0;

        for (int i = 0; i < inputCounts; ++i) {
            std::cin >> inputName >> inputSalary >> inputAward;

            employees[i] = Employee(inputName, inputSalary, inputAward);

            maxNameLength = std::max(static_cast<int>(inputName.size()), maxNameLength);
            maxSalaryLength = std::max(static_cast<int>(log10(inputSalary)) + 1, maxSalaryLength);
            maxAwardLength = std::max(static_cast<int>(log10(inputAward)) + 1, maxAwardLength);
        }

        for (const auto& i : employees) {
            std::cout <<
                std::setw(maxNameLength) << i.name << "|  " <<
                std::setw(maxSalaryLength) << i.salary << "|  " <<
                std::setw(maxAwardLength) << i.award << "\n";
        }
    }


    return 0;
}
