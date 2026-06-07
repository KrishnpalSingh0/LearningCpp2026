cmake_minimum_required(VERSION 3.10)

project(VirtualFileSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(VirtualFileSystem

    src/main.cpp
    src/FileSystemComponent.cpp
    src/File.cpp
    src/Directory.cpp
    src/FileSystem.cpp
    src/CommandParser.cpp
    src/CommandHandler.cpp
)
