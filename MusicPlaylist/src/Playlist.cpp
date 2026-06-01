#include "Playlist.h" 
#include <iostream>  
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

Playlist::Playlist()
{
    m_playlistId = 0; 
    m_name = "";      
    m_nextSongId = 1; 
    m_currentIdx = 0; 
}

Playlist::Playlist(int id, string name)
{
    m_playlistId = id;
    m_name = name;    
    m_nextSongId = 1; 
    m_currentIdx = 0; 
}

int Playlist::getPlaylistId()
{
    return m_playlistId;
}

string Playlist::getName()
{
    return m_name; 
}

vector<Song> &Playlist::getSongs()
{
    return m_songs;
}
void Playlist::addSong(string filePath)
{
    for (Song &s : m_songs)
    {
        if (s.getFilePath() == filePath)
        {
            cout << "Song already exists in playlist.\n";
            return; 
        }
    }
    Song s(m_nextSongId, filePath);
    m_songs.push_back(s);
    m_nextSongId++;
}

void Playlist::removeSong()
{
    if (m_songs.empty())
    {
        cout << "No songs in playlist.\n";
        return;
    }
    cout << "Songs in playlist:\n";
    for (Song &s : m_songs)
    {
        s.display(); 
    }
    cout << "Enter Song ID to remove: ";
    int id;
    cin >> id;
    for (int i = 0; i < m_songs.size(); i++)
    {
        if (m_songs[i].getId() == id)
        {
            cout << m_songs[i].getTitle() << " removed successfully.\n";
            m_songs.erase(m_songs.begin() + i);
            return;
        }
    }
    cout << "Song ID not found.\n";
}

Song *Playlist::getCurrentSong()
{
    if (m_songs.empty())
        return nullptr;   
    return &m_songs[m_currentIdx]; 
}

Song *Playlist::getNextSong()
{
    if (m_songs.empty())
        return nullptr;

    m_currentIdx++; 
    if (m_currentIdx >= m_songs.size())
        m_currentIdx = 0;
    return &m_songs[m_currentIdx];
}
Song *Playlist::getPreviousSong()
{
    if (m_songs.empty())
        return nullptr;

    m_currentIdx--; 
    if (m_currentIdx < 0)
        m_currentIdx = m_songs.size() - 1; 
    return &m_songs[m_currentIdx];
}
bool Playlist::moveUp(int index)
{
    if (index <= 0 || index >= m_songs.size())
        return false;

    swap(m_songs[index], m_songs[index - 1]);
    return true;
}

bool Playlist::moveDown(int index)
{
    if (index < 0 || index >= m_songs.size() - 1)
        return false;         
                              
    swap(m_songs[index], m_songs[index + 1]); 
    return true;
}

void Playlist::setPlaylistId(int id)
{
    m_playlistId = id; 
}
bool Playlist::isEmpty(){
    return m_songs.empty();
}
