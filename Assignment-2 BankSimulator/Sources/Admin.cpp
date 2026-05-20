#include "../Headers/Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(int userId, string userName,
             string password, int adminId)
    : User(userId, userName, password)
{
    m_adminId = adminId;
}
void Admin::closeAccount(Account *account)
{
    if (account != nullptr)
        account->closeAccount();
}
void Admin::viewDetails(Account *account)
{
    if (account != nullptr)
    {
        cout << "Account No: " << endl
             << account->getAccountNumber();
        cout << "Balance: " << endl
             << account->getBalance();
    }
}