#include <iostream>
using namespace std;
int main(){
    int num = 4;
    int num2 = 7;

    const int* ptr = &num;// we can only change the address
    cout<<"The address of num = "<<ptr<<endl;
    ptr = &num2;
    cout<<"The address of num2 = "<<ptr<<endl;
    
    int* const ptr1 = &num2; // we can only change the value 
    cout<<"The value of num2 = "<<*ptr1<<endl;
    *ptr1 = 3;
    cout<<"The new value of num2 = "<<*ptr1<<endl;

    const int* const ptr2 = & num2; //we cannot modify and and the value


    return 0;
}