#include <iostream>
using namespace std;

class Engine
{
public:
    void start()
    {
        cout << "Engine start" << endl;
    }
};

class Car
{   
    Engine e;
    public:
        void drive()
            {   e.start();
                cout<<"drive a car";
            }
public:
};
int main()
{   Car c;
    c.drive();
    return 0;
}