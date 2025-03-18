#ifndef MONTH_H
#define MONTH_H

#include <iostream>
#include <map>

class Month {
public:
    Month();
    Month(char first, char second, char third);
    explicit Month(int monthInt);
    ~Month();

    void inputInt();
    void inputStr();
    void outputInt() const;
    void outputStr() const;
    Month nextMonth() const;

private:
    int month;

    static std::map<std::string, int> month2Int;
    static std::string int2Month[];
};

#endif // MONTH_H