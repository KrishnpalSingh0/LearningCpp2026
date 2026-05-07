#include <iostream>
using namespace std;
int* get(){
    int num = 0;
    return &num;    
}
int main(){
    int* p = get();
    cout<<*p<<endl;
    return 0;
}