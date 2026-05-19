#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include "Transaction.h"
using namespace std;

class Account
{
private:
    int m_accountNumber;
    double m_balance;
    string m_openingDate;
    string m_accountStatus;
    Transaction *m_transactions[100];
    int m_totalTransactions;
    string m_customerName;

public:
    Account(
        int accountNumber,
        double balance,
        string openingDate);
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    void closeAccount();
    int getAccountNumber() const;
    string getAccountStatus() const;
    void addTransaction(
        string type,
        double amount);
    void displayMiniStatement();
    void displayBankStatement();
    void setCustomerName(string name);
    string getCustomerName() const;
};
#endif