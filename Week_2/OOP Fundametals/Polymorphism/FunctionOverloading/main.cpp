#include <iostream>
using namespace std;
class FunctionOverloading
{
public:
    FunctionOverloading()
    {
    }
    void calculate(int nVal, double rVal)
    {
        cout << "Perform addition :- " << nVal + rVal << endl;
        ;
    }
    void calculate(int fOperand, int sOperand)
    {
        cout << "Perform multiplication :- " << fOperand * sOperand << endl;
    }
    ~FunctionOverloading()
    {
        cout << "Destructor call" << endl;
    }
};
int main()
{
    FunctionOverloading f;
    f.calculate(3, 4);
    f.calculate(3, 4.5);
    return 0;
}
