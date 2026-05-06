#include <iostream>
using namespace std;
void modifyVal(int& num2Ref){
    num2Ref = 6;
}
int& getMax(int& a, int& b){
    return (a>b) ? a : b;
}
int main(){
    int x = 5;
    cout<<"Value of x = "<<x<<endl;
    int& numRef = x;
    numRef = 9;
    cout<<"the value of numRef = "<<numRef<<endl;

    modifyVal(numRef);

    cout<<"the value of modify numRef = "<<numRef<<endl;
    cout<<"the value of x "<<x<<endl;
    int z = 8, y = 7;

    int& maxValRef = getMax(z,y);
    
    cout<<"before Greater number is = "<<maxValRef<<endl;
    maxValRef = 20;
    cout<<"Now the Greater value is = "<<maxValRef<<endl;
    return 0;
}

