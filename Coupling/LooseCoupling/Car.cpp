#include <iostream>
using namespace std;
#include "IEngine.h"
class PertrolEngine : public IEngine
{
public:
    void start()
    {
        cout << "Petrol Engine start" << endl;
    }
};

class DiselEngine : public IEngine
{
public:
    void start()
    {
        cout << "Disel Engine start" << endl;
    }
};
class Car
{
    IEngine *e;

public:
    Car(IEngine *eng)
    {
        e = eng;
    }
    void carStart()
    {
        e->start();
        cout << "Car engine start" << endl;
    }
};
int main()
{
    PertrolEngine p;
    DiselEngine d;
    Car c(&p);
    c.carStart();
    cout << endl;
    Car c1(&d);
    c1.carStart();
    return 0;
}