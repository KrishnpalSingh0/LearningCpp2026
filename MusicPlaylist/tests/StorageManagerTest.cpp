#include <gtest/gtest.h>
#include "StorageManager.h"
#include <fstream>

using namespace std;

class StorageManagerTest : public testing::Test
{
public:
    PlaylistManager pm;
    StorageManager sm;
    string filePath = "data/playlists.txt";

    void SetUp() override
    {
    }

    void TearDown() override
    {
        remove(filePath.c_str());
    }
};

TEST_F(StorageManagerTest, SaveFile)
{
    pm.createPlaylist("Rock");
    pm.getPlaylists()[0].addSong("song.mp3");
    sm.saveToFile(pm);
    ifstream file(filePath);
    EXPECT_TRUE(file.is_open());
}

TEST_F(StorageManagerTest, LoadPlaylist)
{
    ofstream file(filePath);
    file << "PLAYLIST|1|Rock\n";
    file << "SONG|1|song.mp3\n";
    file << "END\n";
    file.close();
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}

TEST_F(StorageManagerTest, PlaylistName)
{
    ofstream file(filePath);
    file << "PLAYLIST|1|Workout\n";
    file << "END\n";
    file.close();
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists()[0].getName(), "Workout");
}

TEST_F(StorageManagerTest, SongCount)
{
    ofstream file(filePath);
    file << "PLAYLIST|1|Pop\n";
    file << "SONG|1|a.mp3\n";
    file << "SONG|2|b.mp3\n";
    file << "END\n";
    file.close();
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists()[0].getSongs().size(), 2);
}

TEST_F(StorageManagerTest, EmptyFile)
{
    ofstream file(filePath);
    file.close();
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}

