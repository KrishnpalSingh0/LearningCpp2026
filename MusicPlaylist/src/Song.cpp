#include "Song.h"
#include <iostream>
using namespace std;

Song::Song()
{
    m_id = 0;
    m_title = "";
    m_filePath = "";
}

Song::Song(int id, string filePath)
{
    m_id = id;
    m_filePath = filePath;
    int slash = filePath.find_last_of("/");
    int dot = filePath.find_last_of(".");
    m_title = filePath.substr(slash + 1, dot - slash - 1);
}

int Song::getId()
{
     return m_id;
}

string Song::getTitle()
{
    return m_title;
}

string Song::getFilePath()
{
    return m_filePath; 
}

void Song::display()
{
     cout << m_id << ". " << m_title << endl;
}