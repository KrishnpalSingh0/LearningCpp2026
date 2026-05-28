#include <iostream>
using namespace std;

class Debugging
{
public:
    void swapping(int &num1, int &num2);
    void printNum();
};

void Debugging::swapping(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void Debugging::printNum()
{
    int val =10;
    for (int i = 0; i < 10; i++)
    {
        cout<< i << " " << endl;
    }
}

int main()
{
    Debugging d;
    int a = 10, b = 23;
    cout << "Before swapping a and b " << a << ", " << b << endl;
    d.swapping(a, b);
    cout << "After swapping a and b " << a << ", " << b << endl;
    d.printNum();
    return 0;
}