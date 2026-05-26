#pragma once
#include "PlaylistManager.h"

class StorageManager
{
public:
    void saveToFile(PlaylistManager &pm);
    void loadFromFile(PlaylistManager &pm);
};