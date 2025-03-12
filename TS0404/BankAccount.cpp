#include "BankAccount.h"

int BankAccount::total = 0;

BankAccount::BankAccount()
    : balance(0) {}

BankAccount::BankAccount(const int input)
    : balance(input) {
    total += input;
}

void BankAccount::withdraw(const int output) {
    this->balance -= output;
    total -= output;
}

void BankAccount::save(const int input) {
    this->balance += input;
    total += input;
}

int BankAccount::getBalance() const {
    return this->balance;
}

int BankAccount::getAllMoneyInBank() {
    return total;
}
