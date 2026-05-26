#include "StorageManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void StorageManager::saveToFile(PlaylistManager &pm)
{
    ofstream file("data/playlists.txt");
    vector<Playlist> &playlists = pm.getPlaylists();
    for (int i = 0; i < playlists.size(); i++)
    {   Playlist &p = playlists[i];
        file << "PLAYLIST|"
             << p.getPlaylistId()
             << "|"
             << p.getName()
             << "\n";
        vector<Song> &songs = p.getSongs();
        for (int j = 0; j < songs.size(); j++)
        {   Song &s = songs[j];
            file << "SONG|"
                 << s.getId()
                 << "|"
                 << s.getFilePath()
                 << "\n";
        }
        file << "END\n";
    }
}

void StorageManager::loadFromFile(PlaylistManager &pm)
{
    ifstream file("data/playlists.txt");
    string line;
    Playlist *current = nullptr;
    while (getline(file, line))
    {
        stringstream ss(line);
        string type;
        getline(ss, type, '|');
        if (type == "PLAYLIST")
        {   string idStr;
            string name;
            getline(ss, idStr, '|');
            getline(ss, name);
            int id = stoi(idStr);
            pm.createPlaylist(name);
            current = &pm.getPlaylists()[pm.getPlaylists().size() - 1];
            current->setPlaylistId(id);
        }
        else if (type == "SONG" && current != nullptr)
        {   string songIdStr;
            string path;
            getline(ss, songIdStr, '|');
            getline(ss, path);
            int songId = stoi(songIdStr);
            current->addSong(path);
        }
    }
}