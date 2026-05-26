#pragma once
#include <vector>
#include <string>
#include "Song.h"
using namespace std;

class Playlist
{
private:
    int m_playlistId;
    string m_name;
    vector<Song> m_songs;
    int m_nextSongId;
    int m_currentIdx;

public:
    Playlist();
    Playlist(int id, string name);
    int getPlaylistId();
    string getName();
    vector<Song> &getSongs();
    void addSong(string filePath);
    void removeSong();
    Song *getCurrentSong();
    Song *getNextSong();
    Song *getPreviousSong();
    bool moveUp(int index);
    bool moveDown(int index);
    bool isEmpty();
    void setPlaylistId(int id);
};