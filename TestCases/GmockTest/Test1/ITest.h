#pragma once
class ITest
{
public:
    virtual ~ITest() = default;
    virtual void add() = 0;
    virtual int sub() = 0;
    virtual void div(int num1, int num2) = 0;
};