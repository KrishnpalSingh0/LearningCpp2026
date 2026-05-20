#ifndef BANK_H
#define BANK_H
#include "User.h"
#include "Account.h"
#include "Customer.h"
class Bank
{
private:
    int m_bankCode;
    string m_bankName;
    User **m_users;
    Account **m_accounts;
    int m_totalUsers;
    int m_totalAccounts;
    int m_nextAccountNumber;
    int m_nextUserId;

public:
    Bank(int code, string name);
    ~Bank();
    void addUser(User *user);
    Customer *createCustomer(
        string userName,
        string password,
        double initialDeposit);
    void removeAccount(int accountNumber);
    void createUsers();
    void displayAllAccounts();
    Account *searchAccount(int accountNumber);
    User *login(string userName, string password);
};

#endif