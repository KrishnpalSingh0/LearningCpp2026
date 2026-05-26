#include "TestMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(FirstTestSuite, Division)
{
    TestMock mock;

    EXPECT_CALL(mock, div(6, 0))
        .Times(1);

    mock.div(6, 0);
}

TEST(SecondTestSuite, Submition)
{
    TestMock mock;

    EXPECT_CALL(mock, sub())
        .Times(1)
        .WillOnce(::testing::Return(10));

    EXPECT_EQ(mock.sub(), 10);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}