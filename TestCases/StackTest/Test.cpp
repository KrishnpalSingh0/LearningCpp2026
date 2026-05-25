#include <iostream>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

class stack
{
    vector<int> vstk = {};

public:
    void push(int data)
    {
        vstk.push_back(data);
    }
    int pop()
    {
        if (vstk.size() > 0)
        {
            int value = vstk.back();
            vstk.pop_back();
            return value;
        }
        else
        {
            return -1;
        }
    }
    int size()
    {
        return vstk.size();
    }
};
struct stackTest : public testing::Test
{
    stack s1;
    void SetUp()
    {
        int value[] = {1, 2, 3, 4, 5, 6};
        for (auto &val : value)
        {   
            s1.push(val);
        }
    }
};

TEST_F(stackTest, stackPop)
{
    int lastValue = 6;
    while (lastValue != 1)
    {
        ASSERT_EQ(s1.pop(), lastValue--);
    }
}
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}