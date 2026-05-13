#include <iostream>
using namespace std;
#include <string>

class Constructor{
    public:
    string str;
    int val;
    Constructor(){
        cout<<"Default constructor is called"<<endl;
    }
    Constructor(string str){
        str = str;
        cout<<"The single parameter constructor is called by "<<str<<endl;
    }
    Constructor(string str,int val){
        this->str = str;
        this->val = val;
        cout<<"The double parameter constructor is called by "<<str<<" with value "<<val<<endl;
    }
    Constructor(const Constructor &C){
        str = C.str;
        val = C.val;   
        cout<<str<<", "<<val<<endl;  
    }

    void print(){
        cout << " str is printed " << str <<"mai"<< endl;
    }
   ~Constructor(){
        cout<<"Destructor is call"<<endl;
   }

};
class Demo{
        int* ptr;
        public:
        Demo(int n){
            ptr = new int(n);
            cout<<"Memory allocated"<<endl;
        }
        Demo(int* ptr){
            this->ptr = ptr;
            this->ptr = new int(20);
        }
        void print(){
            cout << "value is " << *ptr;
        }
        ~Demo(){
            delete ptr;
            cout<<"Memory released"<<endl;
        }
};
int main(){
    Constructor c;
    Constructor c1("Object c1");
    c1.print();
    Constructor c2("Object c2",10);
    Constructor c3(c2);
    Demo d(10);

    int* num =new int(10);
    Demo d1(num);
    d1.print();
    return 0;
}