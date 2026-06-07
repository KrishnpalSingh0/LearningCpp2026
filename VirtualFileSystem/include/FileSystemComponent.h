#pragma once

#include <string>

enum class FileSystemComponentType
{
    File,
    Directory
};

class FileSystemComponent
{
protected:
    std::string name;

public:
    FileSystemComponent(const std::string& name);

    virtual ~FileSystemComponent() = default;

    std::string getName() const;

    virtual FileSystemComponentType getType() const = 0;
};
