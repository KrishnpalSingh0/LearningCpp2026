#include <iostream>
using namespace std;
class Animal{
    public:
        virtual void sound() = 0;
};

class Dog : public Animal{
    public:
    void sound(){
        cout<<"Bark"<<endl;
    }
};

class Cat : public Animal{
    public:
        void sound(){
            cout<<"Meow"<<endl;
        }
};
int main(){
    Animal *a1 = new Dog();
    a1->sound();
    Animal *a2 = new Cat();
    a2->sound();
    delete(a1);
    delete(a2);
    return 0;
}