#include <iostream>
using namespace std;
class Pointer
{
public:
    void print1DArray();
    void print2DArray();
    void printAddressOfCharArray();
    void increamentValueOfArray(int *ptr);
    void swapping(int *p, int *q);
    void stringCopy(char *str1, char *str2);
};
void Pointer::print1DArray()
{
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value at idx :- " << i << endl;
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
void Pointer::print2DArray()
{
    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[2];
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter the value at " << i << ", " << j << endl;
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete arr[i];
    }
    delete[] arr;
}

void Pointer::printAddressOfCharArray()
{
    char *arr = new char[5];
    char *ptr = arr;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << (void *)(ptr + i) << "\n";
    }
    cout << endl;
    char name = 'a';
    char *ptr1 = &name;
    cout << name << endl;
    cout << &name << endl;
    cout << (void *)ptr1 << endl;
    delete ptr;
    delete[] arr;
}
void Pointer::swapping(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void Pointer::increamentValueOfArray(int *ptr)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = 2 * ptr[i];
        cout << *(ptr + i) << " ";
    }
    delete ptr;
    cout << endl;
}
void Pointer::stringCopy(char *str1, char *str2)
{
    while ((*str1) = (*str2))
    {
        *str1++;
        *str2++;
    }
    //delete str1,str2;  
}
int main()
{
    Pointer p;
    // p.print1DArray();
     p.print2DArray();
    // p.printAddressOfCharArray();
    //     int arr[4] = {1, 2, 3, 4};
    //     p.increamentValueOfArray(arr);
    //     int first = 2;
    //     int second = 3;
    //     p.swapping(&first, &second);
    //     cout<< first <<", "<< second << endl;
    // int num = 0;
    // int * ptr = &num;
    // int ** ptr1 = &ptr;
    // cout << ptr1 << endl;
    // cout << *ptr1 << endl;
    // cout << &ptr  << endl;
    // cout << **ptr1+1 <<endl;
    // char first[] = "hwlloo";
    // char second[] = "hello";
    // p.stringCopy(first, second);
    // cout << first << endl;
    // int *val = new int(7);
    // cout << *val << endl;
    return 0;
}