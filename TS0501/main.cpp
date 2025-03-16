////////////////////////////////////////////////////////////////////////////////
/// @brief Implements a class with-in specific methods.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/17
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "HotDogStand.h"
#include <iostream>
using namespace std;

int main() {
    HotDogStand stand1("Stand1", 0);
    HotDogStand stand2("Stand2", 100);
    HotDogStand stand3("Stand3");
    stand1.justSold();
    stand2.justSold();
    stand3.justSold();
    stand1.print();
    stand2.print();
    stand3.print();
    std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
    return 0;
}