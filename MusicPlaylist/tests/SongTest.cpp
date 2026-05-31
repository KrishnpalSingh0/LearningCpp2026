#include <gtest/gtest.h>
#include "Song.h"
#include <fstream>

TEST(SongTest, DefaultConstructor)
{
    Song s;
    EXPECT_EQ(s.getId(),0);
    EXPECT_EQ(s.getTitle(),"");
    EXPECT_EQ(s.getFilePath(),"");
}

TEST(SongTest, ParameterizedConstrutor)
{
    Song s(1,"song/music.mp3");
    EXPECT_EQ(s.getId(),1);
    EXPECT_EQ(s.getTitle(),"music");
    EXPECT_EQ(s.getFilePath(),"song/music.mp3");

}

TEST(SongTest, GetID)
{
    Song s(10,"song/music.mp3");
    EXPECT_EQ(s.getId(),10);
}

TEST(SongTest, GetTitle)
{
    Song s(12,"song/Demo.mp3");
    EXPECT_EQ(s.getTitle(),"Demo");
}

TEST(SongTest, GetFilePath)
{
    Song s(12,"song/Demo.mp3");
    EXPECT_EQ(s.getFilePath(),"song/Demo.mp3");
}
