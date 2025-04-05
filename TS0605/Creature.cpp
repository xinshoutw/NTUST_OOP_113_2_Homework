#include "Creature.h"
#include "Diary.h"

#include <iostream>

Creature::Creature(std::string name) {
    this->name = std::move(name);
    startIndex = Diary::dayIndex;
}

Creature::Creature(const std::string& name, const Creature& base) {
    this->body = base.body;
    this->name = name;
    startIndex = Diary::dayIndex;
}

void Creature::PrintStatus() const {
    std::cout << name << "'s status:\n";

    for (const auto& i : body) {
        if (i.second == 0)
            continue;

        std::cout << i.first << " * " << i.second << '\n';
    }

    std::cout.put('\n');
}

void Creature::PrintLog() const {
    std::cout << name << "'s log:\n";

    for (int i = startIndex; i <= Diary::dayIndex; ++i) {
        const std::string& day = Diary::dayNames[i];
        std::cout << "Day " << day << '\n';

        if (i - startIndex >= logData.size())
            continue;
        for (const auto& data : logData[i - startIndex]) {
            if (data.before == 0 && data.after == 0) {
                // ignore
            } else if (data.before == 0) {
                std::cout << name << "'s " << data.body << " appeared (" << data.before << " -> " << data.after << ").\n";
            } else if (data.before < data.after) {
                std::cout << name << "'s " << data.body << " increased (" << data.before << " -> " << data.after << ").\n";
            } else if (data.before > data.after) {
                std::cout << name << "'s " << data.body << " decreased (" << data.before << " -> " << data.after << ").\n";
            }
        }
    }

    std::cout.put('\n');
}

int Creature::operator[](const std::string& id) const {
    return body.at(id);
}

LogProxy Creature::operator[](const std::string& id) {
    return {this, id};
}

// ========= LogProxy =========
int& LogProxy::operator+=(const int cnt) {
    *this = (creature->body[bodyName] + cnt);
    return creature->body[bodyName];
}

int& LogProxy::operator-=(const int cnt) {
    *this = (creature->body[bodyName] - cnt);
    return creature->body[bodyName];
}

LogProxy& LogProxy::operator=(int cnt) {
    int& value = creature->body[bodyName];
    const int dayIndex = Diary::dayIndex - creature->startIndex;

    if (dayIndex >= static_cast<int>(creature->logData.size())) {
        creature->logData.resize(creature->logData.size() + 10);
    }

    creature->logData[dayIndex].emplace_back(bodyName, value, cnt);
    value = cnt;

    return *this;
}
