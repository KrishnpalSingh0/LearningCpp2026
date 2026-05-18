#include "../Headers/Bank.h"
#include "../Headers/Customer.h"
#include "../Headers/Admin.h"
#include <iostream>
#include <fstream>
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
    ofstream file("accounts.txt", ios::app);
    file << customer->getUserId() << " "
         << customer->getUserName() << " "
         << acc->getAccountNumber() << " "
         << acc->getBalance() << " "
         << acc->getAccountStatus()
         << endl;
    file.close();
    return customer;
}

void Bank::removeAccount(int accountNumber)
{
    for (int i = 0; i < m_totalAccounts; i++)
    {
        if (m_accounts[i]->getAccountNumber() == accountNumber)
        {
            m_accounts[i]->closeAccount();
            ofstream file("accounts.txt");
            for (int j = 0; j < m_totalAccounts; j++)
            {
                file << m_accounts[j]->getAccountNumber()
                     << " "
                     << m_accounts[j]->getBalance()
                     << " "
                     << m_accounts[j]->getAccountStatus()
                     << endl;
            }
            file.close();
            cout << "\nAccount Closed Successfully";
            return;
        }
    }
    cout << "\nAccount Not Found!";
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
        Customer *customer = (Customer *)(m_users[i]);
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