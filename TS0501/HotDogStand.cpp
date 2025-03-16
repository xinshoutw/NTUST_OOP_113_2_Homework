#include "HotDogStand.h"
#include <iostream>
#include <ostream>

int HotDogStand::totalSellAmount = 0;
HotDogStand::HotDogStand() = default;

HotDogStand::HotDogStand(const char* id) {
    const size_t len = strlen(id) + 1;
    this->standId = new char[len];
    strcpy(this->standId, id);

    this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount) {
    const size_t len = strlen(id) + 1;
    this->standId = new char[len];
    strcpy(this->standId, id);

    this->hotDogSellAmount = amount;
    HotDogStand::totalSellAmount += amount;
}

HotDogStand::~HotDogStand() = default;

void HotDogStand::justSold() {
    this->hotDogSellAmount++;
    HotDogStand::totalSellAmount++;
}

void HotDogStand::print() const {
    std::cout << this->standId << ' ' << this->hotDogSellAmount << '\n';
}

int HotDogStand::thisStandSoldAmount() const {
    return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() {
    return HotDogStand::totalSellAmount;
}
