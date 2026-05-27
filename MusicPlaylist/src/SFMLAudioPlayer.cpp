#include "SFMLAudioPlayer.h"

bool SFMLAudioPlayer::openFromFile(const string &path)
{
    return m_music.openFromFile(path);
}

void SFMLAudioPlayer::play()
{
    m_music.play();
}

void SFMLAudioPlayer::pause()
{
    m_music.pause();
}

void SFMLAudioPlayer::stop()
{
    m_music.stop();
}

int SFMLAudioPlayer::getStatus()
{
    return m_music.getStatus();
}