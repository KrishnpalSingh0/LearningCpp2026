#include "../Headers/InputHelper.h"
#include <iostream>
#include <string>
using namespace std;

int InputHelper::getIntegerInput()
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input enter integer only" << endl;
        }
        else if (cin.peek() != '\n')
        {
            cin.ignore(1000, '\n');
            cout << "Float value not allowed" << endl;
        }

        else
        {
            return value;
        }
    }
}
string InputHelper::getStringInput()
{
    string str;
    while (true)
    {
        cin >> str;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Inputs" << endl;
        }
    }
    return str;
}