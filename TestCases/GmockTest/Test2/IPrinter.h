#pragma once
#include <string>
class IPrinter {
    public:
    virtual ~IPrinter() = default;
    virtual void printOne() = 0;
    virtual void printTwo() = 0;
    virtual void printThree() = 0;;
};