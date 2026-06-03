#pragma once
#include <string>
using namespace std;

class IAudioPlayer
{
public:
    virtual bool openFromFile(const string &path) = 0;
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual int getStatus() = 0;
    virtual ~IAudioPlayer() {}
};