#pragma once
#include "Playlist.h"
#include "IAudioPlayer.h"

class Player
{
private:
    IAudioPlayer *m_audio;
    Playlist *m_playlist;

public:
    Player(IAudioPlayer *audio);
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void setPlaylist(Playlist *playlist);
};