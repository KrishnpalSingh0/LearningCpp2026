#include <iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the value of n "<<endl;
    cin>> n;
    cout<<"Enter the value of m "<<endl;
    cin>>m;
    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i]= new int[m];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"Enter the value at "<<i<<","<<j<<" ; ";
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    delete [] arr;
    return 0;
}