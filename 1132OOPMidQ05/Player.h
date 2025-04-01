#pragma once
#include "Buff.h"
#include <vector>

using namespace std;

class Player {
private:
    float power;
    float defense;
    float speed;
    vector<Buff> buffs;
    void sortBuffs();

public:
    Player(float power, float defense, float speed)
        : power(power)
        , defense(defense)
        , speed(speed) {};
    void parse();
    void addBuff(const Buff& buff);
    void removeBuff(std::string name);
    void cleanse();
    void tick(int time);
};
