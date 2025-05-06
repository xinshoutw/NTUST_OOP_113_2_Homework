//
// Created by xinshou on 2025/5/6.
//

#ifndef SCHOOL_H
#define SCHOOL_H

#include <cstdint>
#include <ostream>
#include <string>

class School {
public:
    virtual ~School() = default;
    School(std::string name, const uint32_t studentAmount)
        : name(std::move(name))
        , studentAmount(studentAmount) {}

    void admissions(const float amount) {
        if (amount <= 0)
            return;
        studentAmount += static_cast<int>(amount);
    }

    virtual void dropouts(const float amount) {
        if (amount <= 0 || static_cast<int>(amount) > studentAmount)
            return;
        studentAmount -= static_cast<int>(amount);
    }

    void transfer(const float amount, School& toSchool) {
        if (amount <= 0 || static_cast<int>(amount) > studentAmount)
            return;

        dropouts(amount);
        toSchool.admissions(amount);
    }

    friend std::ostream& operator<<(std::ostream& os, const School& school) {
        return os << school.name << '\t' << school.studentAmount << '\t' << school.studentAmountNextYear;
    }

protected:
    std::string name;
    uint32_t studentAmount{};
    uint32_t studentAmountNextYear{studentAmount};
};

class PrivateSchool final : public School {
public:
    PrivateSchool(const std::string& name, const uint32_t studentAmount)
        : School(name, studentAmount) {}

    void dropouts(const float amount) override {
        if (amount <= 0 || static_cast<int>(amount) > studentAmount)
            return;
        studentAmount -= static_cast<int>(amount);

        if (isDropoutLimit) {
            studentAmountNextYear -= 100;
        } else {
            isDropoutLimit = true;
        }
    }

private:
    bool isDropoutLimit = false;
};

class PublicSchool final : public School {
public:
    PublicSchool(const std::string& name, const uint32_t studentAmount)
        : School(name, studentAmount) {}

    PublicSchool(const std::string& name, const uint32_t studentAmount, const double growing_rate)
        : School(name, studentAmount)
        , growing_rate(growing_rate) {}

    void apply_growth() {
        studentAmountNextYear += static_cast<int>(growing_rate * studentAmountNextYear);
    }

    void dropouts(const float amount) override {
        if (amount <= 0 || static_cast<int>(amount) > studentAmount)
            return;
        studentAmount -= static_cast<int>(amount);

        if (static_cast<int>(amount) > 100) {
            studentAmountNextYear = static_cast<int>(studentAmountNextYear * 0.95);
        }
    }

private:
    double growing_rate = 0.05;
};

#endif // SCHOOL_H
