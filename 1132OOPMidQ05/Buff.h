#pragma once
#include "Attribute.h"
#include <iostream>

class Buff {
public:
    int priority;
    Attribute type;
    std::string name;
    float addend;
    float multiplier;
    int remainingTime;
    bool isDebuff;

    // Constructor
    Buff(Attribute type, std::string name, int priority, float addend, float multiplier, int duration)
        : type(type)
        , name(name)
        , priority(priority)
        , addend(addend)
        , multiplier(multiplier)
        , remainingTime(duration) {
        if ((multiplier < 1 && addend <= 0) || (multiplier == 1 && addend < 0)) {
            isDebuff = true;
        } else {
            isDebuff = false;
        }
    }
};
