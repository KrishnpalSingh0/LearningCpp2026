#include <gtest/gtest.h>
#include "PlaylistManager.h"
#include <fstream>

class PlaylistManagerTest : public testing::Test
{
public:
    PlaylistManager pm;

    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PlaylistManagerTest, Constructor)
{
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}

TEST_F(PlaylistManagerTest, CreatePlaylist)
{
    pm.createPlaylist("Morning");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}

TEST_F(PlaylistManagerTest, OpenPlaylist)
{
    pm.createPlaylist("Workout");
    Playlist *p = pm.openPlaylist("Workout");
    ASSERT_NE(p, nullptr);
    EXPECT_EQ(p->getName(), "Workout");
}

TEST_F(PlaylistManagerTest, DuplicatePlaylist)
{
    pm.createPlaylist("LongDrive");
    pm.createPlaylist("LongDrive");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}

TEST_F(PlaylistManagerTest, DeletePlaylist)
{
    pm.createPlaylist("Party");
    pm.deletePlaylistByName("Party");
    EXPECT_EQ(pm.getPlaylists().size(), 0);
}

TEST_F(PlaylistManagerTest, OpenPlaylistNotFound)
{
    Playlist *p = pm.openPlaylist("Party");
    EXPECT_EQ(p, nullptr);
}

TEST_F(PlaylistManagerTest, DeletePlaylistNotFound)
{
    pm.createPlaylist("Party");
    pm.deletePlaylistByName("Enjoy");
    EXPECT_EQ(pm.getPlaylists().size(), 1);
}