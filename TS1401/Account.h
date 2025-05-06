//
// Created by xinshou on 2025/5/6.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <exception>

class NegativeDeposit final : std::exception{};
class InsufficientFunds final : std::exception {};

class Account {
public:
    Account() {
        balance = 0;
    }

    Account(double initialDeposit) {
        balance = initialDeposit;
    }

    double getBalance() {
        return balance;
    }

    // returns new balance or -1 if error
    double deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            throw NegativeDeposit{};
        return balance;
    }

    // return new balance or -1 if invalid amount
    double withdraw(double amount) {
        if ((amount > balance) || (amount < 0))
            throw InsufficientFunds{};
        else
            balance -= amount;
        return balance;
    }

private:
    double balance;
};

#endif // ACCOUNT_H
