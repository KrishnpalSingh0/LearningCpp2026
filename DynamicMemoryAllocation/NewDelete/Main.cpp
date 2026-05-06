#include <iostream>
using namespace std;
int main(){
    cout<<"Use of new operator "<<endl;
    int *ptr = new int(40);
    cout<<"The value of ptr = "<<*ptr<<endl;
    cout<<"The address of ptr = "<<ptr<<endl;
    int *arr = new int[3];
    arr[0] = 23;
    *(arr+1)= 32;
    arr[2] = 45;
    cout<<"Arrays :- ";
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete ptr;
    delete[] arr;
    return 0;
}