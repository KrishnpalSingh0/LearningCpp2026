#include <iostream>
#include "../Headers/Bank.h"
#include "../Headers/Menu.h"
#include "../Headers/InputHelper.h"
using namespace std;

void displayMainMenu()
{
    cout << "\nBANK MANAGEMENT SYSTEM" << endl;
    cout << "==============================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;
    cout << "Enter Choice: " << endl;
}
int main()
{
    Bank bank(101, "ABC BANK");
    bank.createUsers();
    int choice;
    do
    {
        displayMainMenu();
        choice = InputHelper ::getIntegerInput();
        switch (choice)
        {
        case 1:
            Menu::loginMenu(bank);
            break;
        case 2:
            cout << "Thank You For Using Bank System" << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 2);
    return 0;
}