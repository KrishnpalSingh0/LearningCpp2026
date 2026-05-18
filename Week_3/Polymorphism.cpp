#include <iostream>
using namespace std;
class Polymorphism
{
public:
    Polymorphism(void);
    int add(int num1, int num2);
    float add(float num1, float num2);
    ~Polymorphism();
    virtual void display();
};
Polymorphism::Polymorphism()
{
    cout << "Constructor call\n";
}
int Polymorphism::add(int num1, int num2)
{
    return num1 + num2;
}

float Polymorphism::add(float num1, float num2)
{
    return num1 + num2;
}
Polymorphism::~Polymorphism()
{
    cout << "Desctructor call \n";
}
void Polymorphism::display()
{
    cout << "The display method of Base class" << endl;
}
class Derived : public Polymorphism
{
public:
    void display();
};
void Derived ::display()
{
    cout << "The display method of Derived class" << endl;
}
int main()
{
    Polymorphism *p = new Derived();
    cout << "Int Value Addition :- " << p->add(3, 4) << endl;
    cout << "Float Value Addition :- " << p->add(2.3f, 4.2f) << endl;
    p->display();
    delete p;
    return 0;
}