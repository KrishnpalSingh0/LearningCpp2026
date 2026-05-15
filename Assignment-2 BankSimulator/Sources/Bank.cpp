#include "../Headers/Bank.h"
#include "../Headers/Customer.h"
#include "../Headers/Admin.h"
#include <iostream>
using namespace std;

Bank::Bank(int code, string name)
{
    m_bankCode = code;
    m_bankName = name;
    m_users = new User *[100];
    m_accounts = new Account *[100];
    m_totalUsers = 0;
    m_totalAccounts = 0;
}

Bank::~Bank()
{
    delete[] m_users;
    delete[] m_accounts;
}

void Bank::createUsers()
{
    Admin *mainAdmin = new Admin(
        101,
        "admin@Bank",
        "admin123",
        5001);
    addUser(mainAdmin);
}
void Bank::addUser(User *user)
{
    m_users[m_totalUsers++] = user;
}

User *Bank::login(string userName, string password)
{
    for (int i = 0; i < m_totalUsers; i++)
    {
        if (m_users[i]->login(userName, password))
        {
            return m_users[i];
        }
    }
    return nullptr;
}
Customer *Bank::searchCustomer(int userId)
{
    for (int i = 0; i < m_totalUsers; i++)
    {
        if (m_users[i]->getUserId() == userId)
        {
            return (Customer *)m_users[i];
        }
    }

    return nullptr;
}

Account *Bank::searchAccount(int accountNumber)
{
    for (int i = 0; i < m_totalAccounts; i++)
    {
        if (m_accounts[i]->getAccountNumber() == accountNumber)
        {
            return m_accounts[i];
        }
    }
    return nullptr;
}
Customer *Bank::createCustomer(string userName, string password, double initialDeposit)
{
    int userId = 100 + m_totalUsers;
    Customer *customer = new Customer(userId, userName, password, 500 + m_totalUsers);
    addUser(customer);
    Account *acc = new Account(1000 + m_totalAccounts, initialDeposit, "14-05-2026");

    m_accounts[m_totalAccounts++] = acc;

    customer->setAccount(acc);

    return customer;
}

void Bank::removeAccount(int accountNumber)
{
    Account *acc = searchAccount(accountNumber);
    if (acc != nullptr)
    {
        acc->closeAccount();
        cout << "\nAccount Closed Successfully";
    }
    else
    {
        cout << "\nAccount Not Found!";
    }
}

void Bank::displayAllAccounts()
{
    cout << "\n\n===== ALL BANK ACCOUNTS =====";
    if (m_totalAccounts == 0)
    {
        cout << "\nNo Accounts Found!";
        return;
    }
    for (int i = 0; i < m_totalUsers; i++)
    {
        Customer *customer =
            dynamic_cast<Customer *>(m_users[i]);
        if (customer != nullptr &&
            customer->getAccount() != nullptr)
        {
            Account *acc =
                customer->getAccount();
            cout << "\n--------------------------";
            cout << "\nCustomer Name: "
                 << customer->getUserName();
            cout << "\nCustomer ID: "
                 << customer->getUserId();
            cout << "\nAccount Number: "
                 << acc->getAccountNumber();
            cout << "\nBalance: "
                 << acc->getBalance();
            cout << "\nStatus: "
                 << acc->getAccountStatus();
            cout << endl;
        }
    }
}