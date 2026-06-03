#include "PlaylistManager.h"
#include <iostream>
using namespace std;

PlaylistManager::PlaylistManager()
{
    m_nextId = 1;
}

vector<Playlist> &PlaylistManager::getPlaylists()
{
    return m_playlists;
}

void PlaylistManager::createPlaylist(string name)
{
    for (int i = 0; i < m_playlists.size(); i++)
    {
        if (m_playlists[i].getName() == name)
        {
            cout << "Playlist Already Exists \n";
            return;
        }
    }
    Playlist p(m_nextId, name);
    m_playlists.push_back(p);
    m_nextId++;
}

Playlist *PlaylistManager::openPlaylist(const string &name)
{
    for (int i = 0; i < m_playlists.size(); i++)
    {
        if (m_playlists[i].getName() == name)
        {
            return &m_playlists[i];
        }
    }
    return nullptr;
}

void PlaylistManager::viewAllPlaylist()
{
    for (int i = 0; i < m_playlists.size(); i++)
    {
        cout << m_playlists[i].getPlaylistId()
             << " - "
             << m_playlists[i].getName()
             << endl;
    }
}
void PlaylistManager::deletePlaylistByName(const string &name)
{
    for (int i = 0; i < m_playlists.size(); i++)
    {
        if (m_playlists[i].getName() == name)
        {
            m_playlists.erase(m_playlists.begin() + i);
            cout << "Playlist \"" << name << "\" deleted successfully.\n";
            return;
        }
    }
    cout << "Playlist \"" << name << "\" not found.\n";
}
