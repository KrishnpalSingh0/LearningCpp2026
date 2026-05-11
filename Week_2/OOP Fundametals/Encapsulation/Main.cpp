#include <iostream>
using namespace std;
class Employee{
    private:
      int age;
      string name;
      int salary;
    public:
     void setSalary(int sal){
        salary = sal;
     }
     int getSalary(){
        return salary;
     }
     void setAge(int age){
        this->age = age;
     }
     int getAge(){
        return age;
     }
     void setName(string name){
        this->name = name;
     }
     string getName(){
        return name;
     }
};
int main(){
    Employee e1;
    e1.setAge(23);
    e1.setName("Anish");
    e1.setSalary(45000);
    cout<<"The name of Employee 1 "<<e1.getName()<<", salary "<<e1.getSalary()<<", age "<<e1.getAge()<<endl;
    Employee e2;
    e2.setAge(24);
    e2.setName("Ansh");
    e2.setSalary(87000);
    cout<<"The name of Employee 2 "<<e2.getName()<<", salary "<<e2.getSalary()<<", age "<<e2.getAge()<<endl;

    return 0;
}