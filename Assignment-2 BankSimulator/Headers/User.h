#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;
class User
{
protected:
    int m_userId;
    string m_userName;
    string m_dob;
    string m_password;

public:
    User(int userId, string userName, string password);
    virtual ~User() {}
    int getUserId() const;
    string getUserName() const;
    bool login(string userName, string password);
    void logout();
};

#endif