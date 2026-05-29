#include <iostream>
#include <string>
using namespace std;
void printArray()
{
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void doublePointer()
{
    int x = 20;
    int *ptr = &x;
    int **ptr1 = &ptr;
    cout << x << endl;
    cout << *ptr << endl;
    cout << **ptr1 << endl;
}

struct Student
{
    string name;
    int id;
    void print();
};
void Student::print()
{
    cout << "The name of student " << name << " and id " << id << endl;
}
int *add(int &a, int &b)
{
    int *ptr = nullptr;
    int result = a + b;
    ptr = &result;
    return ptr;
}
int *multiply(int &a, int &b)
{
    int *ptr = nullptr;
    int result = a * b;
    ptr = &result;
    return ptr;
}
struct student {
    string name ;
    int id;
};

void swap(int *a, int *b)
{
    int temp = *a;
        *a = *b;
        *b = temp;
}
void dinamicArray()
{
    int row,clm;
    cin>>row>>clm;
    int **arr = new int*[row];
    for(int i = 0;i<row;i++){
        arr[i] = new int[clm];
    }
    for(int i = 0;i<row;i++)
    {
        for (int j = 0;j<clm;j++){
            cin>>arr[i][j];
        }
    }
    for(int i = 0;i<row;i++){
        for (int j = 0;j<clm;j++)
        {
            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }
}
int main()
{   
    
    student *s1 = new student[3];
    for (int i = 0;i<3;i++){
        cin>>s1[i].id;
        cin>>s1[i].name;
    }
    for(int i = 0;i<3;i++){
      cout<<(s1+i)->id;
      cout<<(s1+i)->name;
    }
    delete []s1;
    int a = 4, b = 5;
    swap(&a,&b);
    int *ptr = add(a, b);
    cout << "addition is "
         << *ptr << endl;
    ptr = multiply(a, b);
    cout << "Multiplication is " << *ptr << endl;

    Student *s;
    s->name = "Sahil";
    s->id = 1;
    s->print();
    int x = 10;
    int *ptr1 = &x;
    cout << x << endl;
    cout << ptr1 << endl;
    cout << *ptr1 << endl;

    return 0;
}