#include "BankAccount.h"

BankAccount::BankAccount()
    : balance(0) {}

BankAccount::BankAccount(const int input)
    : balance(input) {
    total += input;
}

void BankAccount::withdraw(int output) {
    this->balance -= output;
    total -= output;
}

void BankAccount::save(int input) {
    this->balance += input;
    total += balance;
}

int BankAccount::getBalance() const {
    return this->balance;
}

int BankAccount::getAllMoneyInBank() {
    return total;
}
