#pragma once

#include "Directory.h"
#include "File.h"
#include <memory>

class FileSystem
{
private:
    std::shared_ptr<Directory> root;

public:
    FileSystem();

    bool createDir(const std::string& name);

    bool createFile(const std::string& name);

    void list() const;

    bool writeToFile(const std::string& fileName,
                     const std::string& content);

    void readFile(const std::string& fileName);
};
