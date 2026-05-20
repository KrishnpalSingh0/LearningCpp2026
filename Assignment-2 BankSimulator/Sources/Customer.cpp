#include "../Headers/Customer.h"
#include "../Headers/Bank.h"

#include <iostream>
using namespace std;

Customer::Customer(
    int userId,
    string userName,
    string password,
    int customerId)
    : User(userId, userName, password)
{
    m_customerId = customerId;
    m_account = nullptr;
}
void Customer::deposit(int amount)
{
    if (m_account != nullptr)
        m_account->deposit(amount);
}
void Customer::withdraw(int amount)
{
    if (m_account != nullptr)
        m_account->withdraw(amount);
}
void Customer::displayBalance()
{
    if (m_account != nullptr)
        cout << "Balance: " << endl
             << m_account->getBalance();
}
void Customer::displayMiniStatement()
{
    if (m_account != nullptr)
    {
        m_account->displayMiniStatement();
    }
}
void Customer::displayBankStatement()
{
    if (m_account != nullptr)
    {
        m_account->displayBankStatement();
    }
}
void Customer::setAccount(Account *account)
{
    m_account = account;
}
int Customer::getCustomerId() const
{
    return m_customerId;
}
Account *Customer::getAccount() const
{
    return m_account;
}