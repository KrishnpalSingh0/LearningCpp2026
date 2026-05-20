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
    m_nextAccountNumber = 1000;
    m_nextUserId = 101;
    ifstream file("accounts.txt");
    string customerName;
    string password;
    int accNo;
    int userId;
    double balance;
    string status;
    while (file >> userId >> customerName >> password >> accNo >> balance >> status)
    {
        if (accNo >= m_nextAccountNumber)
        {
            m_nextAccountNumber = accNo + 1;
        }
        if (userId >= m_nextUserId)
        {
            m_nextUserId = userId + 1;
        }
        Customer *customer = new Customer(
            userId,
            customerName,
            password,
            500 + m_totalUsers);
        addUser(customer);
        Account *acc = new Account(accNo, balance);
        acc->setCustomerName(customerName);
        if (status == "CLOSED")
        {
            acc->closeAccount();
        }
        m_accounts[m_totalAccounts++] = acc;
        customer->setAccount(acc);
    }
    file.close();
}

Bank::~Bank()
{
    for (int i = 0; i < m_totalUsers; i++)
        delete m_users[i];

    for (int i = 0; i < m_totalAccounts; i++)
        delete m_accounts[i];
    delete[] m_users;
    delete[] m_accounts;
}

void Bank::createUsers()
{
    Admin *mainAdmin = new Admin(
        1111,
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
    int userId = m_nextUserId;
    Customer *customer = new Customer(userId, userName, password, 500 + m_totalUsers);
    addUser(customer);
    Account *acc = new Account(m_nextAccountNumber, initialDeposit);
    acc->setCustomerName(userName);
    m_accounts[m_totalAccounts++] = acc;
    customer->setAccount(acc);
    ofstream file("accounts.txt", ios::app);
    file << customer->getUserId()
         << " "
         << customer->getUserName()
         << " "
         << customer->getPassword()
         << " "
         << acc->getAccountNumber()
         << " "
         << acc->getBalance()
         << " "
         << acc->getAccountStatus()
         << endl;
    file.close();
    m_nextAccountNumber++;
    m_nextUserId++;
    return customer;
}

void Bank::removeAccount(int accountNumber)
{
    for (int i = 0; i < m_totalUsers; i++)
    {
        Customer *customer = dynamic_cast<Customer *>(m_users[i]);
        if (customer != nullptr && customer->getAccount() != nullptr)
        {
            Account *acc = customer->getAccount();
            if (acc->getAccountNumber() == accountNumber)
            {
                acc->closeAccount();
                ofstream file("accounts.txt", ios::app);

                file << customer->getUserId()
                     << " "
                     << customer->getUserName()
                     << " "
                     << customer->getPassword()
                     << " "
                     << acc->getAccountNumber()
                     << " "
                     << acc->getBalance()
                     << " "
                     << acc->getAccountStatus()
                     << endl;
                file.close();
                cout << "\nAccount Closed Successfully";
                return;
            }
        }
    }
    cout << "\nAccount Not Found!";
}

void Bank::displayAllAccounts()
{
    ifstream file("accounts.txt");
    string name;
    string password;
    int accNo;
    int userId;
    double balance;
    string status;
    cout << "\n===== ALL ACCOUNTS =====";
    while (file >> userId >> name >> password >> accNo >> balance >> status)
    {
        cout << "\n-------------------";
        cout << "\nUser Id: "
             << userId;
        cout << "\nCustomer Name: "
             << name;
        cout << "\nAccount Number: "
             << accNo;
        cout << "\nBalance: "
             << balance;
        cout << "\nStatus: "
             << status
             << endl;
    }
    file.close();
}