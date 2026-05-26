#include "ITest.h"
#include <gmock/gmock.h>

class TestMock : public ITest
{
public:
    MOCK_METHOD(int, sub, (), (override));
    MOCK_METHOD(void, add, (), (override));
    MOCK_METHOD(void, div, (int num1, int num2), (override));
};