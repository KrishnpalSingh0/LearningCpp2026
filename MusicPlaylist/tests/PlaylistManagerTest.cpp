#include <gtest/gtest.h>
#include "PlaylistManager.h"
#include <fstream>

TEST(PlaylistManagerTest, Constructor)
{
    PlaylistManager pm;
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}

TEST(PlaylistManagerTest, CreatePlaylist)
{
    PlaylistManager pm;
    pm.createPlaylist("Morning");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}

TEST(PlaylistManagerTest, OpenPlaylist)
{
    PlaylistManager pm;
    pm.createPlaylist("Workout");
    Playlist *p = pm.openPlaylist("Workout");
    ASSERT_NE(p, nullptr);
    EXPECT_EQ(p->getName(), "Workout");
}

TEST(PlaylistManagerTest, DuplicatePlaylist)
{
    PlaylistManager pm;
    pm.createPlaylist("LongDrive");
    pm.createPlaylist("LongDrive");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}

TEST(PlaylistManagerTest, DeletePlaylist)
{
    PlaylistManager pm;
    pm.createPlaylist("Party");
    pm.deletePlaylistByName("Party");
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}

TEST(PlaylistManagerTest, OpenPlaylistNotFound)
{
    PlaylistManager pm;
    Playlist *p = pm.openPlaylist("Party");
    EXPECT_EQ(p, nullptr);
}

TEST(PlaylistManagerTest, DeletePlaylistNotFound)
{
    PlaylistManager pm;
    pm.createPlaylist("Party");
    pm.deletePlaylistByName("Enjoy");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}