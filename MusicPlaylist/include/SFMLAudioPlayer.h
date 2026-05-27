#pragma once
#include "IAudioPlayer.h"
#include <SFML/Audio.hpp>

class SFMLAudioPlayer : public IAudioPlayer
{
private:
    sf::Music m_music;

public:
    bool openFromFile(const string &path) override;
    void play() override;
    void pause() override;
    void stop() override;
    int getStatus() override;
};