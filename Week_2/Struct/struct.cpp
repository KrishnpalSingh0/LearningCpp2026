#include <iostream>
using namespace std;
struct Demo
{
    int num1, num2;
    void showData()
    {
        cout << "the value of num1:- " << num1 << ", and num2:- " << num2 << endl;
    }
};

struct Demo1
{
    struct Demo
    {
        int x, y;
    } d3;
    int num1, num2;
};
struct Demo2
{
    int val1, val2;
    Demo1 d;
};
struct employee
{
    int id;
    int age;
    double wage;
};

int main()
{
    Demo d;
    d.num1 = 2;
    d.num2 = 3;
    d.showData();
    Demo1 d1 = {{4, 8}, 10, 34};
    cout << "Nested Struct values " << d1.d3.x << ", " << d1.d3.y << endl;
    Demo2 d2 = {1, 4, {{1, 2}, 10, 20}};
    cout << d2.val1 << ", " << d2.val2 << endl;
    cout << d2.d.d3.x << ", " << d2.d.d3.y << endl;
    cout << "Another nested struct value " << d2.d.num1 << ", " << d2.d.num2 << endl;
    employee e = {
        1,
        2,
    };
    cout << e.wage << endl;// it will print the result zero
    return 0;
}
