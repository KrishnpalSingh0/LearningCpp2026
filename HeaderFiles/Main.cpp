#include "Add.h"
#include "Multiplication.h"
#include "Subtraction.h"
#include "Division.h"
#include <iostream>
using namespace std;

float multiplication(){
    float num1,num2;
    cout<<"Enter the value of num1"<<endl;
    cin>>num1;
    cout<<"Enter the value of num2"<<endl;
    cin>>num2;
    cout<<"Mutliplication of "<<num1<<" and "<<num2<<" = ";
    return mutliply(num1,num2);
}
int addition(){
    int num1,num2;
    cout<<"Enter the value of num1"<<endl;
    cin>>num1;
    cout<<"Enter the value of num2"<<endl;
    cin>>num2;
    cout<<"Addition of "<<num1<<" and "<<num2<<" = ";
    return add(num1,num2);
}
int subtraction(){
    int num1,num2;
    cout<<"Enter the value of num1"<<endl;
    cin>>num1;
    cout<<"Enter the value of num2"<<endl;
    cin>>num2;
    cout<<"Subtraction of "<<num1<<" and "<<num2<<" = ";
    return sub(num1,num2);
}
float division(){
    float num1,num2;
    cout<<"Enter the value of num1"<<endl;
    cin>>num1;
    cout<<"Enter the value of num2"<<endl;
    cin>>num2;
    cout<<"Division of "<<num1<<" and "<<num2<<" = ";
    return divide(num1,num2);
}
int main(){
    cout<<"Multiplication"<<endl;
    float mulResult= multiplication();
    cout<<mulResult<<endl<<endl;
    cout<<"Addition"<<endl;
    int addResult= addition();
    cout<<addResult<<endl<<endl;
    cout<<"Subtraction"<<endl;
    int subResult= subtraction();
    cout<<subResult<<endl<<endl;
    cout<<"Division"<<endl;
    int divResult= division();
    cout<<divResult<<endl;
   
}