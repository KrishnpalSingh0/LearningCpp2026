#include "IPrinter.h"
#include <gmock/gmock.h>
class TestMock : public IPrinter
{
public:
    MOCK_METHOD(void, printOne, (), (override));
    MOCK_METHOD(void, printTwo, (), (override));
    MOCK_METHOD(void, printThree, (), (override));
};