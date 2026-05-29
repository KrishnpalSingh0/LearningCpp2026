#include <iostream>
using namespace std;

void refPo()
{
    int x = 10;
    int &nRef = x;
    int *ptr = &x;
    cout << endl;
    cout << (nRef + 3) << endl;
    cout << (*ptr - 5) << endl;
    cout << x << endl;
}

void pointerConse()
{
    const int x = 50;
    const int *ptr = &x;
    cout << *ptr + 3 << endl;
}

void increment(int &x)
{
    cout << x + 1 << endl;
}

void increment1(int *x)
{
    cout << *x + 1 << endl;
}

void increment2(int &y)
{
    int *p = &y;
    cout << *p << endl;
    int *&nRef = p;
    cout << nRef++ << endl;
}

int &ref()
{
    static int x = 3;
    return x;
}

int *point()
{
    int *ptr = new int(3);
    return ptr;
}
int main()
{
    int s = 11;
    cout << s << endl;
    increment(s);
    cout << s << endl;
    increment1(&s);
    cout << s << endl;
    increment2(s);
    int k = ref();
    cout << k << endl;
    int *h = point();
    delete h;
    cout << *h << endl;
    refPo();

    return 0;
}