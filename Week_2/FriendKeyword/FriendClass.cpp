#include <iostream>
using namespace std;
class FriendClass{
    int m_nVal;
    float m_rVal;
    protected:
        int m_nNum;
    public:
        FriendClass(){
           m_nVal =0;
           m_nNum = 0;
           m_rVal = 0.0;
        }
        FriendClass(int x, int y, float z){
            m_nNum = x;
            m_nVal = y;
            m_rVal = z;
        }
        ~FriendClass(){
            cout<<"Destructor is call"<<endl;
        }
        friend class Storage;
};
class Storage{
    public:
        void display(FriendClass &f){
            cout<<"val1:- "<<f.m_nVal<<", val2:- "<<f.m_rVal<<", val3:- "<<f.m_nNum<<endl;
        }
        friend class Display;
};
class Display{
    public: 
        void show(Storage &s, FriendClass &f){
            s.display(f);
        }
};
int main(){
    FriendClass f;
    FriendClass f1(2,3,4.43);
    Storage s;
    cout<<"Call by storage friend class"<<endl;
    FriendClass f2(30,40,5.32);
    s.display(f1);
    Display d;
    cout<<"Call by Display friend class"<<endl;
    d.show(s, f2);
    return 0;
}