////////////////////////////////////////////////////////////////////////////////
/// @brief Define a class named "BankAccount", implement from the header file.
///
/// @file main.cpp
/// @author xinshoutw <admin@xinshou.tw>
/// @date 2025/03/09
/// @version 0.0.1
////////////////////////////////////////////////////////////////////////////////

#include "BankAccount.h"
#include <iostream>

int BankAccount::total = 0;

int main() {
    BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
    std::cout << BankAccount::getAllMoneyInBank() << std::endl;
    bankAccount1.withdraw(100);
    std::cout << bankAccount1.getBalance() << std::endl;
    std::cout << BankAccount::getAllMoneyInBank() << std::endl;
    bankAccount2.save(50);
    std::cout << bankAccount2.getBalance() << std::endl;
    std::cout << BankAccount::getAllMoneyInBank() << std::endl;

    return 0;
}
