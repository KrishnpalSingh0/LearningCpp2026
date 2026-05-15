#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Account.h"

class Admin : public User
{
private:
    int m_adminId;

public:
    Admin(int userId, string userName, string password, int adminId);
    void viewDetails(Account *account);
    void closeAccount(Account *account);
    Account *searchAccount(int accountNumber);
};

#endif