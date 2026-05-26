#pragma once
#include <vector>
#include <string>
#include "Playlist.h"

using namespace std;

class PlaylistManager
{
private:
    vector<Playlist> m_playlists;
    int m_nextId;

public:
    PlaylistManager();
    vector<Playlist> &getPlaylists();
    void createPlaylist(string name);
    void deletePlaylist(int id);
    Playlist *openPlaylist(const string &name);
    void deletePlaylistByName(const string &name);
    void viewAllPlaylist();
};