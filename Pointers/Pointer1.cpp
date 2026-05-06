#include <iostream>
using namespace std;
int main(){
    int a = 5;
    int *ptr = &a;
    cout<<ptr<<endl;// address of a
    cout<<*ptr<<endl;// derefrencing ptr
    cout<<&ptr<<endl;// address of ptr
    cout<<a<<endl;// value of a
    int **ptr1 = &ptr;  // store address of ptr to pointer ptr1;
    cout<<**ptr1<<endl; //derefrencing 
    return 0;
}