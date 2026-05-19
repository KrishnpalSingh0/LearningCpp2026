#include "../Headers/Account.h"
#include "../Headers/Transaction.h"
#include <iostream>
using namespace std;

Account::Account(int accountNumber, double balance, string openingDate)
{
    m_accountNumber = accountNumber;
    m_balance = balance;
    m_openingDate = openingDate;
    m_accountStatus = "ACTIVE";
    m_totalTransactions = 0;
    addTransaction(
        "ACCOUNT OPENED",
        balance);
}
Account::~Account()
{
    for (int i = 0; i < m_totalTransactions; i++)
    {
        delete m_transactions[i];
    }
}
void Account::setCustomerName(string name)
{
    m_customerName = name;
}
string Account::getCustomerName() const
{
    return m_customerName;
}
void Account::addTransaction(string type, double amount)
{
    Transaction *transaction = new Transaction(m_totalTransactions + 1, type, amount, "14-05-2026", m_balance);
    m_transactions[m_totalTransactions++] = transaction;
}
void Account::deposit(double amount)
{
    if (m_accountStatus == "ACTIVE")
    {
        m_balance += amount;
        addTransaction("DEPOSIT", amount);
        Transaction::saveTransactionInFile(m_customerName, m_accountNumber,
                                           "DEPOSIT", amount, m_balance);
        cout << "\nAmount Deposited Successfully";
        cout << "\nCurrent Balance: " << m_balance << endl;
    }
    else
    {
        cout << "\nAccount Is Closed!" << endl;
    }
}
void Account::withdraw(double amount)
{
    if (m_accountStatus == "ACTIVE" && m_balance >= amount)
    {
        m_balance -= amount;
        addTransaction("DEPOSIT", amount);
        Transaction::saveTransactionInFile(m_customerName, m_accountNumber,
                                           "WITHDRAW", amount, m_balance);
        cout << "Withdrwal Successfully" << endl;
        cout << "Current Balance:- " << m_balance << endl;
    }
    else
    {
        cout << "Transaction Failed" << endl;
    }
}
void Account::displayMiniStatement()
{
    cout << "\n===== MINI STATEMENT =====" << endl;
    int start = m_totalTransactions - 3;
    if (start < 0)
    {
        start = 0;
    }
    for (int i = start; i < m_totalTransactions; i++)
    {
        m_transactions[i]->displayTransaction();
        cout << endl;
    }
}
void Account::displayBankStatement()
{
    cout << "\n===== BANK STATEMENT =====" << endl;
    int start = m_totalTransactions - 6;
    if (start < 0)
    {
        start = 0;
    }
    for (int i = start; i < m_totalTransactions; i++)
    {
        m_transactions[i]->displayTransaction();
        cout << endl;
    }
}
double Account::getBalance() const
{
    return m_balance;
}
void Account::closeAccount()
{
    m_accountStatus = "CLOSED";
}
int Account::getAccountNumber() const
{
    return m_accountNumber;
}
string Account::getAccountStatus() const
{
    return m_accountStatus;
}