#include "IPrinter.h"
#include <iostream>
using namespace std;
class Implementation : public IPrinter
{
public:
    void printOne()
    {
        cout << "Hello this is printOne\n";
    }
    void printTwo()
    {
        cout << "Hello this is printTwo\n";
    }
    void printThree()
    {
        cout << "Hello this is printThree\n";
    }
};