#ifndef BankAccount_H
#define BankAccount_H

class BankAccount {
private:
    int balance;
    static int total;

public:
    BankAccount();
    BankAccount(int input);
    void withdraw(int output);
    void save(int input);
    int getBalance() const;
    static int getAllMoneyInBank();
};

#endif // BankAccount_H