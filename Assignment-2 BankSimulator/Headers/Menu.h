#ifndef MENU_H
#define MENU_H
#include "Bank.h"
#include "Customer.h"
#include "Admin.h"

class Menu
{
public:
    static void loginMenu(Bank &bank);
    static void customerMenu(Bank &bank, Customer *customer);
    static void adminMenu(Bank &bank, Admin *admin);
};

#endif
