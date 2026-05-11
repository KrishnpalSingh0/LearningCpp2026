#include <iostream>
using namespace std;
class Mensuration{
   public:
        const float pi = 3.14;
        int radius ;
        int length;
        int breadth;
    
        void setValue(int r, int l, int b){
            radius = r;
            length = l;
            breadth = b;
        }
};
// single Level
class Rectangle : public Mensuration{
    public:
    int side;
        int areaOfRectangle(){
          return length*breadth; 
        }
        int perameterOfRectangle(){
            return 2*(length+breadth);
        }
};
// Multilevel
class Square : public Rectangle{
    public:
        int areaOfSquare(){
            return side*side;
        }
};
// Hierarchical
class Circle : public Mensuration{
    public:
        void setValue(int r){
            radius = r;
        }
        float areaOfCircle(){
            return pi*radius*radius;
        }
};

int main()
{
    Rectangle r;
    r.setValue(3,4,5);
    int result1 = r.areaOfRectangle();
    cout<<"Area of rectangle is "<<result1<<endl;
    int result2 = r.perameterOfRectangle();
    cout<<"Perameter of rectangle is "<<result2<<endl;
    Circle c;
    c.setValue(24);
    float result3 = c.areaOfCircle();
    cout<<"Area of circle is "<<result3<<endl;
    return 0;
}