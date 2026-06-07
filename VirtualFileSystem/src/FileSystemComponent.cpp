#include "../include/FileSystemComponent.h"

FileSystemComponent::FileSystemComponent(const std::string& name)
    : name(name)
{
}

std::string FileSystemComponent::getName() const
{
    return name;
}
