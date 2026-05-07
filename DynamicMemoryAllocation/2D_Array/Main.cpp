#include <iostream>
using namespace std;
int main(){
    int row,clm;
    cout<<"Enter the size of row"<<endl;
    cin>>row;
    cout<<"Enter the size of clm"<<endl;
    cin>>clm;
    int** arr = new int*[row];
    for(int i = 0;i<row;i++){
        arr[i] = new int[clm];
    }
    for(int i= 0; i<row; i++){
        for(int j= 0; j<clm; j++){
            cout<<"Enter value at "<<i<<","<<j<<" - ";
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<clm; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<row; i++){
        delete[] arr[i];
    }
    
    delete []arr;
    return 0;
}