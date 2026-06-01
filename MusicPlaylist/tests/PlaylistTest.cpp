#include <gtest/gtest.h>
#include "Playlist.h"
#include <fstream>

TEST(PlaylistTest, Constructor)
{
    Playlist p;
    EXPECT_EQ(p.getPlaylistId(), 0);
    EXPECT_EQ(p.getName(), "");
    EXPECT_EQ(p.getNextSong(), nullptr);
}

TEST(PlaylistTest, ParameterizedConstructor)
{
    Playlist p(1, "Enjoy");
    EXPECT_EQ(p.getPlaylistId(), 1);
    EXPECT_EQ(p.getName(), "Enjoy");
}

TEST(PlaylistTest, GetNextSong)
{
    Playlist p;
    p.addSong("song1");
    p.addSong("song2");
    p.addSong("song3");
    Song *s = p.getNextSong();
    ASSERT_NE(s, nullptr);
    EXPECT_EQ(s->getTitle(),"song2");
}

TEST(PlaylistTest, CheckPlaylistEmpty)
{
    Playlist p;
    EXPECT_EQ(p.getNextSong(), nullptr);
}

TEST(PlaylistTest, GetCurrentSong)
{
    Playlist p;
    EXPECT_EQ(p.getCurrentSong(), nullptr);
}