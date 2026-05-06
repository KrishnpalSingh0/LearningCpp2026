#include <iostream>
using namespace std;
void passByAddress(int* ptr){
    *ptr = 8;
}
int main(){
    int num = 5;
    cout<<"Value of num := "<<num<<endl;
    passByAddress(&num);
    cout<<"Change value by passing address = "<<num<<endl;
    return 0;
}