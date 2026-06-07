#include "../include/FileSystem.h"

#include <iostream>

FileSystem::FileSystem()
{
    root = std::make_shared<Directory>("/");
}

bool FileSystem::createDir(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    return root->addChild(std::make_shared<Directory>(name));
}

bool FileSystem::createFile(const std::string& name)
{
    if (name.empty())
    {
        return false;
    }

    return root->addChild(std::make_shared<File>(name));
}

void FileSystem::list() const
{
    auto children = root->getChildren();

    for (const auto& child : children)
    {
        if (child->getType() == FileSystemComponentType::Directory)
        {
            std::cout << "[DIR] ";
        }
        else
        {
            std::cout << "[FILE] ";
        }

        std::cout << child->getName() << std::endl;
    }
}

bool FileSystem::writeToFile(const std::string& fileName,
                             const std::string& content)
{
    auto component = root->getChild(fileName);

    if (component == nullptr)
    {
        return false;
    }

    if (component->getType() != FileSystemComponentType::File)
    {
        return false;
    }

    auto file = std::dynamic_pointer_cast<File>(component);

    file->setContent(content);

    return true;
}

void FileSystem::readFile(const std::string& fileName)
{
    auto component = root->getChild(fileName);

    if (component == nullptr)
    {
        std::cout << "File not found" << std::endl;
        return;
    }

    if (component->getType() != FileSystemComponentType::File)
    {
        std::cout << "Not a file" << std::endl;
        return;
    }

    auto file = std::dynamic_pointer_cast<File>(component);

    std::cout << file->getContent() << std::endl;
}
