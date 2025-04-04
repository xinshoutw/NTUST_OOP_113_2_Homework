#include "Diary.h"

int Diary::dayIndex = -1;
std::string Diary::dayName;
std::vector<std::string> Diary::dayNames;

void Diary::NewDay(const std::string& dayName) {
    Diary::dayName = dayName;
    dayNames.push_back(dayName);
    ++dayIndex;
}
