#include "../include/File.h"

File::File(const std::string& name)
    : FileSystemComponent(name)
{
}

void File::setContent(const std::string& text)
{
    content = text;
}

std::string File::getContent() const
{
    return content;
}

void File::appendContent(const std::string& text)
{
    content += text;
}

FileSystemComponentType File::getType() const
{
    return FileSystemComponentType::File;
}
