#pragma once
class IEngine
{
public:
    virtual void start() = 0;
    virtual ~IEngine() = default;
};