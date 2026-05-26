#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    m_playlist = nullptr;
}

void Player::play()
{

    if (!m_playlist)
        return;

    Song *s = m_playlist->getCurrentSong(); 
    if (!s)
        return;
    if (m_music.getStatus() == sf::SoundSource::Stopped)
    {
        if (!m_music.openFromFile(s->getFilePath()))
        {
            cout << "Error: could not open " << s->getFilePath() << endl;
            return;
        }
    }

    m_music.play();
    cout << "Playing: " << s->getTitle() << endl;
}

void Player::pause()
{
    m_music.pause();
    Song *s = m_playlist->getCurrentSong();
    cout << "Pause: " << s->getTitle() << endl;
}

void Player::stop()
{

    m_music.stop();
}

void Player::next()
{
    if (!m_playlist)
        return;

    Song *s = m_playlist->getNextSong();
    if (!s)
        return;
    if (!m_music.openFromFile(s->getFilePath()))
    {
        cout << "Error: could not open " << s->getFilePath() << endl;
        return;
    }

    m_music.play();
    cout << "Playing: " << s->getTitle() << endl;
}

void Player::previous()
{
    if (!m_playlist)
        return;

    Song *s = m_playlist->getPreviousSong();
    if (!s)
        return;
    if (!m_music.openFromFile(s->getFilePath()))
    {
        cout << "Error: could not open " << s->getFilePath() << endl;
        return;
    }
    m_music.play();
    cout << "Playing: " << s->getTitle() << endl;
}

void Player::setPlaylist(Playlist *pl)
{
    m_playlist = pl;
}
