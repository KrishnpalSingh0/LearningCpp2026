#pragma once

#include "FileSystemComponent.h"
#include <vector>
#include <memory>

class Directory : public FileSystemComponent
{
private:
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    Directory(const std::string& name);

    bool addChild(std::shared_ptr<FileSystemComponent> component);

    bool hasChild(const std::string& name) const;

    std::shared_ptr<FileSystemComponent> getChild(const std::string& name);

    std::vector<std::shared_ptr<FileSystemComponent>> getChildren() const;

    FileSystemComponentType getType() const override;
};
