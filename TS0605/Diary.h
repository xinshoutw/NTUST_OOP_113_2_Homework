#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <vector>

class Diary {
public:
    static void NewDay(const std::string& dayName);
    static int dayIndex;
    static std::string dayName;
    static std::vector<std::string> dayNames;
};

#endif // DIARY_H
