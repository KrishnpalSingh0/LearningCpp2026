#include <iostream>
using namespace std;
class Complex
{
private:
    int real, img;

public:
    Complex()
    {
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void display()
    {
        cout << "The addition of " << real << "+ i" << img;
    }
    Complex operator+(Complex &c)
    {
        Complex ans;
        ans.real = real + c.real;
        ans.img = img + c.img;
        return ans;
    }
};
int main()
{
    Complex c1(3, 2);
    c1.display();
    cout << endl;
    Complex c2(5, 3);
    c2.display();
    cout << endl;
    Complex c3 = c1 + c2;
    c3.display();
    cout << endl;
    return 0;
}