#include <iostream>
using namespace std;
class Demo{
    public:
      Demo(){
        cout<<"Default Constructor is call"<<endl;
      }
      int num1 = 3;
      //static member variable 
      static int num2;
      int printAdd(){
        return num1 + num2;
      }
      //static member variable 
      static int num3;
      //static memeber function
      static int printSub(){
        return (num3-num2);
      }
      ~Demo(){
        cout<<"Destructor is call"<<endl;
      }

};
int Demo::num2 = 4;
int Demo::num3 = 9;
int main(){
   Demo d;
   cout<<"Static variables "<<Demo::num2<<", "<<Demo::num3<<endl;
   int result = d.printAdd();
   int output = d.printSub();
   cout<<"call static member function "<<output<<endl;
   cout<<"call instance member function "<<result<<endl;
   return 0;
}