#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of Array"<<endl;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value at "<<i<<" : ";
        cin>>*(arr+i);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
    delete []arr;
    return 0;
}