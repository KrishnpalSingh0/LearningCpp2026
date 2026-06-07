#include "../include/Directory.h"

Directory::Directory(const std::string& name)
    : FileSystemComponent(name)
{
}

bool Directory::addChild(std::shared_ptr<FileSystemComponent> component)
{
    if (hasChild(component->getName()))
    {
        return false;
    }

    children.push_back(component);

    return true;
}

bool Directory::hasChild(const std::string& name) const
{
    for (const auto& child : children)
    {
        if (child->getName() == name)
        {
            return true;
        }
    }

    return false;
}

std::shared_ptr<FileSystemComponent> Directory::getChild(const std::string& name)
{
    for (auto& child : children)
    {
        if (child->getName() == name)
        {
            return child;
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<FileSystemComponent>> Directory::getChildren() const
{
    return children;
}

FileSystemComponentType Directory::getType() const
{
    return FileSystemComponentType::Directory;
}
