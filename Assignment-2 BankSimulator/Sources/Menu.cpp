#include "../Headers/Menu.h"
#include "../Headers/Customer.h"
#include "../Headers/Admin.h"
#include "../Headers/InputHelper.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::loginMenu(Bank &bank)
{
    string userName, password;
    string admin = "admin@Bank";

    cout << "Enter Username: " << endl;
    cin >> userName;

    cout << "Enter Password: " << endl;
    cin >> password;

    User *user = bank.login(userName, password);
    if (user == nullptr)
    {
        cout << "\nInvalid Login!";
        return;
    }
    if (user->getUserName() == admin)
    {
        Admin *admin = (Admin *)user;
        adminMenu(bank, admin);
    }
    else
    {
        Customer *customer = (Customer *)user;
        Account *acc = customer->getAccount();
        if (acc->getAccountStatus() != "ACTIVE")
        {
            cout << "\nYour Account Is ";
            cout << acc->getAccountStatus();
            cout << "\nLogin Denied!";
            return;
        }
        customerMenu(bank, customer);
    }
}

void Menu::customerMenu(Bank &bank, Customer *customer)
{
    int choice;
    do
    {
        cout << "\n\n===== CUSTOMER MENU =====";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Balance";
        cout << "\n4. Mini Statement";
        cout << "\n5. Bank Statement";
        cout << "\n6. Logout";
        cout << "\nEnter Choice: ";
        choice = InputHelper ::getIntegerInput();
        switch (choice)
        {
        case 1:
        {
            int amount;
            cout << "Enter Amount: ";
            amount = InputHelper ::getIntegerInput();
            customer->deposit(amount);
            break;
        }
        case 2:
        {
            int amount;
            cout << "Enter Amount: ";
            amount = InputHelper ::getIntegerInput();
            customer->withdraw(amount);
            break;
        }
        case 3:
            customer->displayBalance();
            break;
        case 4:
            customer->displayMiniStatement();
            break;
        case 5:
            customer->displayBankStatement();
            break;
        case 6:
            customer->logout();
            break;
        default:
            cout << "\nInvalid Choice!";
        }
    } while (choice != 6);
}

void Menu::adminMenu(Bank &bank, Admin *admin)
{
    int choice;
    do
    {
        cout << "\n\n===== ADMIN MENU =====";
        cout << "\n1. Open Account";
        cout << "\n2. Search Account";
        cout << "\n3. View All Accounts";
        cout << "\n4. Close Account";
        cout << "\n5. Logout";
        cout << "\nEnter Choice: ";
        choice = InputHelper ::getIntegerInput();
        switch (choice)
        {
        case 1:
        {
            string name;
            string password;
            int deposit;
            cout << "\nEnter Customer Name: ";
            cin >> name;
            cout << "Enter Customer Password: ";
            cin >> password;
            cout << "Enter Initial Deposit: ";
            deposit = InputHelper::getIntegerInput();
            Customer *customer =
                bank.createCustomer(
                    name,
                    password,
                    deposit);
            cout << "\nCustomer Created Successfully!";
            cout << "\nCustomer ID: "
                 << customer->getUserId();

            cout << "\nAccount Number: "
                 << customer->getAccount()->getAccountNumber();
            break;
        }
        case 2:
        {
            int accNo;
            cout << "Enter Account No: ";
            accNo = InputHelper::getIntegerInput();
            Account *acc =
                bank.searchAccount(accNo);
            if (acc != nullptr)
            {
                cout << "\n===== ACCOUNT DETAILS =====";
                cout << "\nAccount Number: "
                     << acc->getAccountNumber();
                cout << "\nBalance: "
                     << acc->getBalance();
                cout << "\nStatus: "
                     << acc->getAccountStatus();
                for (int i = 0; i < 100; i++)
                {
                    Customer *customer =
                        bank.searchCustomer(100 + i);
                    if (customer != nullptr &&
                        customer->getAccount() == acc)
                    {
                        cout << "\nCustomer Name: "
                             << customer->getUserName();
                        cout << "\nCustomer ID: "
                             << customer->getUserId();
                        break;
                    }
                }
            }
            else
            {
                cout << "\nAccount Not Found!";
            }
            break;
        }
        case 3:
        {
            bank.displayAllAccounts();
            break;
        }
        case 4:
        {
            int accNo;
            cout << "Enter Account No: ";
            accNo = InputHelper ::getIntegerInput();
            bank.removeAccount(accNo);
            break;
        }
        case 5:
            admin->logout();
            break;
        default:
            cout << "\nInvalid Choice!";
        }
    } while (choice != 5);
}