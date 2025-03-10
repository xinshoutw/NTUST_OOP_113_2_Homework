////////////////////////////////////////////////////////////////////////////////
/// @brief Print input data in a table form.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/07
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <vector>

struct Employee {
    std::string name;
    int32_t salary;
    int32_t award;

    explicit Employee(std::string name, const int32_t salary, const int32_t award)
        : name(std::move(name))
        , salary(salary)
        , award(award) {}
};

int main() {
    int32_t input_counts;
    std::string input_tmp_name;
    int32_t input_tmp_salary;
    int32_t input_award;

    while (std::cin >> input_counts) {
        std::vector<Employee> employees;
        employees.reserve(input_counts);

        int32_t max_name_length = 0;
        int32_t max_salary_length = 0;
        int32_t max_award_length = 0;

        for (int i = 0; i < input_counts; ++i) {
            std::cin >> input_tmp_name >> input_tmp_salary >> input_award;

            employees.emplace_back(input_tmp_name, input_tmp_salary, input_award);

            max_name_length = std::max(static_cast<int>(input_tmp_name.size()), max_name_length);
            max_salary_length = std::max(static_cast<int>(log10(input_tmp_salary)) + 1, max_salary_length);
            max_award_length = std::max(static_cast<int>(log10(input_award)) + 1, max_award_length);
        }

        for (const auto& i : employees) {
            std::cout << std::setw(max_name_length) << i.name << "|  " << std::setw(max_salary_length) << i.salary << "|  " << std::setw(max_award_length)
                      << i.award << "\n";
        }
    }

    return 0;
}
