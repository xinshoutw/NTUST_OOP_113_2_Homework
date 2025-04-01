#include "Player.h"
#include <algorithm>

bool compare(int a) {
    return false;
}

void Player::sortBuffs() {
    sort(buffs.begin(), buffs.end(), [](const Buff& lhs, const Buff& rhs) {
        if (lhs.priority == rhs.priority)
            return lhs.type < rhs.type;
        else
            return lhs.priority > rhs.priority;
    });
}

void Player::parse() {
    sortBuffs();

    bool empty = true;
    float newPower = power;
    float newDefense = defense;
    float newSpeed = speed;
    for (const auto& i : buffs) {
        if (i.remainingTime <= 0) {
            continue;
        }
        empty = false;

        if (i.type == Attribute::POWER) {
            newPower = newPower * i.multiplier + i.addend;
        } else if (i.type == Attribute::DEFENSE) {
            newDefense = newDefense * i.multiplier + i.addend;
        } else if (i.type == Attribute::SPEED) {
            newSpeed = newSpeed * i.multiplier + i.addend;
        }
    }

    if (empty) {
        cout << "Power: " << power << '\n' << "Defense: " << defense << '\n' << "Speed: " << speed << '\n' << "No Buff\n";
        return;
    }

    cout << "Power: " << newPower << '\n' << "Defense: " << newDefense << '\n' << "Speed: " << newSpeed << '\n' << "Buff List: ";

    cout << buffs[0].name;
    for (int i = 1; i < static_cast<int>(buffs.size()); ++i) {
        if (buffs[i].remainingTime <= 0)
            continue;
        cout << ", " << buffs[i].name;
    }

    cout << '\n';
}

void Player::addBuff(const Buff& buff) {
    tick(1);

    string name = buff.name;
    const auto found = find_if(buffs.begin(), buffs.end(), [&name](const Buff& b) {
        return b.name == name;
    });

    if (found == buffs.end()) {
        this->buffs.push_back(buff);
        cout << "Add BUFF " << buff.name << " success!\n";
    } else {
        buffs.erase(found);
        this->buffs.push_back(buff);
        cout << "Add BUFF " << buff.name << " extended!\n";
    }
}

void Player::removeBuff(std::string name) {
    const auto found = find_if(buffs.begin(), buffs.end(), [&name](const Buff& b) {
        return b.name == name;
    });

    if (found == buffs.end()) {
        cout << "Remove BUFF " << name << " failed!\n";
    } else {
        cout << "Remove BUFF " << name << " success!\n";
        buffs.erase(found);
    }
}

void Player::cleanse() {
    sortBuffs();

    if (buffs.empty()) {
        cout << "Cleanse nothing\n";
    } else {
        cout << "Cleanse: ";

        int bSize = static_cast<int>(buffs.size());
        for (int i = 0; i < bSize; ++i) {
            Buff& tmp = buffs[i];

            if (tmp.isDebuff) {
                cout << tmp.name;
                if (i != bSize - 1) {
                    cout << ", ";
                }

                buffs.erase(buffs.begin() + i);
                i--;
                bSize--;
            }
        }

        cout << '\n';
    }
}

void Player::tick(const int time) {
    for (auto& i : buffs) {
        i.remainingTime -= time;
    }
}