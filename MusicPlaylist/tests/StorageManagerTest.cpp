#include <gtest/gtest.h>
#include "StorageManager.h"
#include <fstream>

TEST(StorageManagerTest, SaveFile)
{
    PlaylistManager pm;
    pm.createPlaylist("Rock");
    pm.getPlaylists()[0].addSong("song.mp3");
    StorageManager sm;
    sm.saveToFile(pm);
    ifstream file("data/playlists.txt");
    EXPECT_TRUE(file.is_open());
}

TEST(StorageManagerTest, LoadPlaylist)
{
    ofstream file("data/playlists.txt");
    file << "PLAYLIST|1|Rock\n";
    file << "Song|1|song.m3\n";
    file << "END\n";
    file.close();
    PlaylistManager pm;
    StorageManager sm;
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists().size(),1);        
}

TEST(StorageManagerTest, PlaylistName)
{
    ofstream file("data/playlists.txt");
    file << "PLAYLIST|1|Workout\n";
    file << "END\n";
    file.close();
    PlaylistManager pm;
    StorageManager sm;
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists()[0].getName(), "Workout");
}

TEST(StorageManagerTest, SongCount)
{
    ofstream file("data/playlists.txt");
    file << "PLAYLIST|1|Pop\n";
    file << "SONG|1|a.mp3\n";
    file << "SONG|2|b.mp3\n";
    file << "END\n";
    file.close();
    PlaylistManager pm;
    StorageManager sm;
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists()[0].getSongs().size(), 2);
}

TEST(StorageManagerTest, EmptyFile)
{
    ofstream file("data/playlists.txt");
    file.close();
    PlaylistManager pm;
    StorageManager sm;
    sm.loadFromFile(pm);
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}