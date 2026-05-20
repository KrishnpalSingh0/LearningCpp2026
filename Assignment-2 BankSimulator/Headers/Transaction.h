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
    double m_balanceAfter;

public:
    Transaction(int id, string type, double amount,double balance);
    void displayTransaction() const;
   static void saveTransactionInFile(
        string customerName,
        int accountNumber,
        string type,
        double amount,
        double balance);
        
};
#endif