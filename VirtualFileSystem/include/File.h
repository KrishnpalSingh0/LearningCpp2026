#pragma once

#include "FileSystemComponent.h"

class File : public FileSystemComponent
{
private:
    std::string content;

public:
    File(const std::string& name);

    void setContent(const std::string& text);

    std::string getContent() const;

    void appendContent(const std::string& text);

    FileSystemComponentType getType() const override;
};
