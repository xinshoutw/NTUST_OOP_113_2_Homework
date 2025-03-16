#ifndef HOT_DOG_STAND_H
#define HOT_DOG_STAND_H

#include <cstring>

class HotDogStand {
public:
    HotDogStand();
    HotDogStand(const char* id);
    HotDogStand(const char* id, int amount);
    ~HotDogStand();
    void justSold();
    void print() const;
    int thisStandSoldAmount() const;
    static int allStandSoldAmount();

private:
    char* standId{};
    int hotDogSellAmount{};
    static int totalSellAmount;
};

#endif // HOT_DOG_STAND_H