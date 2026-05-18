#include "../Headers/Transaction.h"
#include <iostream>
#include <fstream>
using namespace std;

Transaction::Transaction(int id, string type,
                         double amount, string date,
                         double balance)
{
    m_transactionId = id;
    m_type = type;
    m_amount = amount;
    m_date = date;
    m_balanceAfter = balance;
}
void Transaction::displayTransaction() const
{
    cout << m_transactionId
         << " | " << m_type
         << " | " << m_amount
         << " | " << m_date
         << " | " << m_balanceAfter;
}
void Transaction::saveTransaction(int accNo, string type, double amount, double balance)
{
    ofstream file("transactions.txt", ios::app);

    file << accNo << " "
         << type << " "
         << amount << " "
         << balance
         << endl;

    file.close();
}