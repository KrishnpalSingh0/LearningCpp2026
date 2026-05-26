#include <gtest/gtest.h>
#include "TestMock.h"
using namespace std;
TEST(UsingSequence, printInSequence)
{
    TestMock mock;
    ::testing::Sequence s;

    EXPECT_CALL(mock, printOne()).InSequence(s);
    EXPECT_CALL(mock, printTwo()).InSequence(s);
    EXPECT_CALL(mock, printThree()).InSequence(s);

    mock.printOne();
    mock.printTwo();
    mock.printThree();
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}