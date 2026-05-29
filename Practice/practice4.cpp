#include <iostream>
using namespace std;

class Employee
{
public:
    string name;
    int id;
    double salary;
    void updateSalary(Employee &emp, int newSalaray);
    void printEmployee(Employee *emp);
};

void Employee::updateSalary(Employee &emp, int newSalary)
{
    salary += newSalary;
    cout << "Updated Salary " << salary << endl;
}

void Employee::printEmployee(Employee *emp)
{
    cout << "Employee id :- " << emp->id
         << "Employee name :- " << emp->name
         << "Employee salary :- " << emp->salary
         << endl;
}

int main()
{
    Employee *e = new Employee[2];
    for (int i = 0; i < 2; i++)
    {
        cin >> e[i].id;
        cin >> e[i].name;
        cin >> e[i].salary;
    }
    for (int i = 0; i < 2; i++)
    {
        e[i].updateSalary(e[i], 100);
    }
    for (int i = 0; i < 2; i++)
    {
        e[i].printEmployee(&e[i]);
    }
    delete[] e;
    return 0;
}