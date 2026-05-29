#include <iostream>
using namespace std;

class Book
{
public:
    int id;
    string author;
    string title;
    void printDetails();
};

void Book::printDetails()
{
    cout << "Book ID: " << id << ", Title: " << title << ", Author:" << author << endl;
}

int main()
{
    Book *b = new Book[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter id :";
        cin >> b[i].id;
        cout << "Enter Title :";
        cin >> b[i].title;
        cout << "Enter author  :";
        cin >> b[i].author;
    }
    for (int i = 0; i < 3; i++)
    {
        b[i].printDetails();
    }
    delete[]b;
    
}