#include <gtest/gtest.h>
#include "Playlist.h"
#include <fstream>

class PlaylistTest : public testing::Test
{
public:
    Playlist p;
    void SetUp() override {}
    void TearDown() override {}
};
TEST_F(PlaylistTest, Constructor)
{
    EXPECT_EQ(p.getPlaylistId(), 0);
    EXPECT_EQ(p.getName(), "");
    EXPECT_EQ(p.getNextSong(), nullptr);
}

TEST_F(PlaylistTest, ParameterizedConstructor)
{
    Playlist p(1,"Enjoy");
    EXPECT_EQ(p.getPlaylistId(), 1);
    EXPECT_EQ(p.getName(), "Enjoy");
}

TEST_F(PlaylistTest, GetNextSong)
{
    p.addSong("song1");
    p.addSong("song2");
    p.addSong("song3");
    Song *s = p.getNextSong();
    ASSERT_NE(s, nullptr);
    EXPECT_EQ(s->getTitle(), "song2");
}

TEST_F(PlaylistTest, CheckPlaylistEmpty)
{

    EXPECT_EQ(p.getNextSong(), nullptr);
}

TEST_F(PlaylistTest, GetCurrentSong)
{

    EXPECT_EQ(p.getCurrentSong(), nullptr);
}