#include "InputValidation.h"
#include <iostream>
#include <limits>
using namespace std;

int InputValidation::getIntValue()
{
    int x;
    while (true)
    {
        cin >> x;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter valid number: ";
        }
        else
        {
            cin.ignore(1000, '\n');
            return x;
        }
    }
}

string InputValidation::getValidString()
{
    string s;
    getline(cin, s);
    return s;
}