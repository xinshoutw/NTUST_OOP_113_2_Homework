#ifndef MONTH_H
#define MONTH_H

#include <iostream>
#include <map>

class Month {
public:
    Month();
    Month(char first, char second, char third);
    Month(int monthInt);
    ~Month();

    void inputInt();
    void inputStr();
    void outputInt();
    void outputStr();
    Month nextMonth();

private:
    int month;

    static std::map<std::string, int> month2Int;
    static std::string int2Month[];
};

#endif // MONTH_H