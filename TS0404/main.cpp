////////////////////////////////////////////////////////////////////////////////
/// @brief Define a class named "BankAccount", implement from the header file.
///
/// @file main.cpp
/// @author xinshoutw <contact@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "BankAccount.h"
#include <iostream>

int main() {
    BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
    std::cout << BankAccount::getAllMoneyInBank() << '\n';
    bankAccount1.withdraw(100);
    std::cout << bankAccount1.getBalance() << '\n';
    std::cout << BankAccount::getAllMoneyInBank() << '\n';
    bankAccount2.save(50);
    std::cout << bankAccount2.getBalance() << '\n';
    std::cout << BankAccount::getAllMoneyInBank() << '\n';
    return 0;
}
