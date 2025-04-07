#include "Creature.h"
#include "Diary.h"

int main() {
    Diary::NewDay("0000");
    Creature unknownA("UA");
    unknownA["leg"] = 16;

    Diary::NewDay("0102");
    Creature unknownB("UB", unknownA);
    unknownB["leg"] += 26;
    unknownA.PrintLog();

    Diary::NewDay("0227");
    unknownA["leg"] = 0;
    unknownA.PrintStatus();
    unknownB.PrintLog();

    Diary::NewDay("0353");
    unknownA["leg"] += 6;
    unknownA["wing"] += 4;
    unknownA.PrintLog();

    Diary::NewDay("1A");
    Creature unknownC("UC");
    unknownC["leg"] += 6;
    unknownC["leg"] += -2;
    unknownC["leg"] -= 4;
    unknownC.PrintStatus();
    unknownC.PrintLog();

    Diary::NewDay("2A");
    unknownC["leg"] -= -2;
    unknownC.PrintStatus();
    unknownC.PrintLog();

    Diary::NewDay("1A");
    unknownC["leg"] = 3;
    unknownC.PrintStatus();
    unknownC.PrintLog();
}
