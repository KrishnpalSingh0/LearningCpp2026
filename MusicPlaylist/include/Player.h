#pragma once
#include <SFML/Audio.hpp>
#include "Playlist.h"

class Player
{
private:
    sf::Music m_music;    
    Playlist *m_playlist; 
   
public:
    Player();
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void setPlaylist(Playlist *playlist);
};