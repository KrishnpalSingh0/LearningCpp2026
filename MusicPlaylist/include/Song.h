#pragma once
#include <string>
using namespace std;

class Song
{
private:
    int m_id;
    string m_title;
    string m_filePath;

public:
    Song();
    Song(int id, string filePath);
    int getId();
    string getTitle();
    string getFilePath();
    void display();
};