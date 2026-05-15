#include "../Headers/User.h"
#include <iostream>
using namespace std;

User::User(int userId, string userName, string password)
{
    m_userId = userId;
    m_userName = userName;
    m_password = password;
}
bool User::login(string userName, string password)
{
    return (m_userName == userName && m_password == password);
}
void User::logout()
{
    cout << "\nUser Logged Out Successfully";
}
int User::getUserId() const
{
    return m_userId;
}

string User::getUserName() const
{
    return m_userName;
}