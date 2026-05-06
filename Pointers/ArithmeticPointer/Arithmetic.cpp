#include <iostream>
using namespace std;
int main(){
    cout<<"Arithmetic Pointer"<<endl;
    int arr[9]={2,3,1,4,5,6,7,8,9};
    int *ptr = arr;
    cout<<"Array :- ";
    for (int i=0;i<9;i++){
        cout<<*(ptr+i)<<" ";
    }
    cout<<endl;
    cout<<ptr<<endl;
    cout<<arr<<endl;
    cout<<*ptr<<endl;

    cout<<"Increment Pointer"<<endl;
    ptr = ptr + 1;
    cout<<"Increment Pointer by 1 = "<<*ptr<<endl;
    cout<<"New address "<<ptr<<endl;

    cout<<"Decrement Pointer "<<endl;
    ptr = ptr - 1;
    cout<<"Decrement Pointer by 1 = "<<*ptr<<endl;
    cout<<"New address = "<<ptr<<endl;

    cout<<"Addition of constant "<<endl;
    ptr = ptr + 3;
    cout<<"Addition of 3 = "<<*ptr<<endl;
    cout<<"New address = "<<ptr<<endl;

    cout<<"Subtraction of constant "<<endl;
    ptr = ptr - 2;
    cout<<"Subtraction of 2 = "<<*ptr<<endl;
    cout<<"New address = "<<ptr<<endl;

    cout<<"subtraction of two pointers"<<endl;
    int *ptr1 = &arr[5];
    int *ptr2 = &arr[8];
    cout<< (ptr2 - ptr1) <<endl;

    cout<<"Comparison of Pointer"<<endl;
    cout<< (ptr2 > ptr1) <<endl;


    return 0;
}