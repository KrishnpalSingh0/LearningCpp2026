#include <iostream>
using namespace std;
#include <string>
class Car{
    private:
        string modelName;
        int manufactureYear;
    protected:
        int engineTemp;
    public: 
        string name;
        int number;
        int fuelTank;
        
        Car(string name, int num, int fuelTank){
        this->name = name;
        this->number = num;
        this->fuelTank = fuelTank;
        }
        void setModel(string name){
            this->modelName = name;
        }
        void setYear(int year){
            this->manufactureYear = year;
        }
        string getModel(){
            return modelName;
        }
        int getYear(){
            return manufactureYear;
        }
        void setTemp(int temp){
            engineTemp = temp;
        }           
};
class SportsCar : public Car{
    public:
        SportsCar(string name, int num, int fuelTank)
        : Car(name, num, fuelTank){}

        void showTemp(){
                cout<<"temperature of car - "<<engineTemp<<endl;
        }
};
int main(){
   SportsCar s("BMW",123,40);
   s.setModel("M4");
   s.setTemp(60);
   s.setYear(2010);
   cout<<"The name of a car is "<<s.name<<" "<<s.getModel()<<" "<<"and number is "<<s.number<<" ";
   s.showTemp();
return 0;
}