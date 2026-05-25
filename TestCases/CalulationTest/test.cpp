#include <iostream>
using namespace std;
#include <gtest/gtest.h>

TEST(TestName, subtest_1)
{
    ASSERT_EQ(1, 1);
}
TEST(MathTest, Addition)
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << endl;
    ASSERT_EQ(10, (num1 + num2));
}
TEST(MathTest, Subtraction)
{
    int num1, num2;
    cin >> num1 >> num2;
    EXPECT_EQ(3, (num1 - num2));  
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}