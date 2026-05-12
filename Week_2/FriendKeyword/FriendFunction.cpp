#include <iostream>
using namespace std;
class Base {
    int num1, num2;
    public:
    Base()
    {
        num1 = num2 = 0;
    }
    Base(int a, int b){
        num1 = a;
        num2 = b;
    }
    protected:
        int pro_var;
    
        friend int sum(Base &obj);
        friend int multiply(Base &obj1);
    public:
    ~Base(){
        cout<<"Destructor call"<<endl;
    }
};
int sum(Base &obj){
    obj.pro_var = obj.num1 + obj.num2;
    return obj.pro_var;
}
int multiply(Base &obj1){
    obj1.pro_var = obj1.num1*obj1.num2;
    return obj1.pro_var;
}
int main(){

    Base obj(4,3);
    int result = sum(obj);
    cout<<"Addition :- "<<result<<endl;
    Base obj1(obj);
    int result1 = multiply(obj1);
    cout<<"Multiplication :- "<<result1<<endl;
    return 0;
}