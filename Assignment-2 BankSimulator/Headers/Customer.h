#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
#include "Account.h"

class Customer : public User
{
private:
    int m_customerId;
    Account *m_account;

public:
    Customer(int userId, string userName, string password, int customerId);
    void closeAccount();
    void setAccount(Account *account);
    void deposit(int amount);
    void withdraw(int amount);
    void displayBalance();
    void displayMiniStatement();
    void displayBankStatement();
    Account *getAccount() const;
};
#endif