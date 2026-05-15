#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
using namespace std;

class Transaction
{
private:
    int m_transactionId;
    string m_type;
    double m_amount;
    string m_date;
    double m_balanceAfter;

public:
    Transaction(int id, string type, double amount, string date, double balance);
    void displayTransaction() const;
};
#endif