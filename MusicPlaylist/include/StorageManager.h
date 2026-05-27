#pragma once
#include "PlaylistManager.h"
#include "IStorage.h"

class StorageManager : public IStorage
{
public:
    void saveToFile(PlaylistManager &pm);
    void loadFromFile(PlaylistManager &pm);
};