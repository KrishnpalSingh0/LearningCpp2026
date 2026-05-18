#include "../Headers/Transaction.h"
#include <iostream>
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