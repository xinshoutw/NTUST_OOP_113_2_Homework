#ifndef CREATURE_H
#define CREATURE_H

#include <map>
#include <string>
#include <vector>

class Creature;
class LogProxy;

struct LogData {
    std::string body;
    int before;
    int after;

    LogData(std::string body, const int before, const int after)
        : body(std::move(body))
        , before(before)
        , after(after) {};
};

class Creature {
public:
    explicit Creature(std::string name);
    Creature(const std::string& name, const Creature& base);

    void PrintStatus() const;
    void PrintLog() const;

    int operator[](const std::string& id) const;
    LogProxy operator[](const std::string& id);

    std::string name;
    std::map<std::string, int> body;
    std::vector<std::vector<LogData>> logData = std::vector<std::vector<LogData>>(10, std::vector<LogData>());
    int startIndex;
};

class LogProxy {
public:
    LogProxy(Creature* creature, std::string body)
        : creature(creature)
        , bodyName(std::move(body)) {};
    int& operator+=(int cnt);
    int& operator-=(int cnt);
    LogProxy& operator=(int cnt);

private:
    Creature* creature;
    std::string bodyName;
};

#endif // CREATURE_H
