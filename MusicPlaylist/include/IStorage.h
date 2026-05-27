#pragma once
#include "PlaylistManager.h"

class IStorage
{
public:
    virtual void saveToFile(PlaylistManager &pm) = 0;
    virtual void loadFromFile(PlaylistManager &pm) = 0;
    virtual ~IStorage() {}
};