#include "../include/CommandHandler.h"

#include <iostream>

bool CommandHandler::execute(const ParsedCommand& command,
                             FileSystem& fs)
{
    if (command.name == "mkdir")
    {
        if (command.args.empty())
        {
            std::cout << "Usage: mkdir <dirname>"
                    << std::endl;

            return true;
        }

        for (const auto& dirName : command.args)
        {
            if (fs.createDir(dirName))
            {
                std::cout << "Directory created: "
                        << dirName << std::endl;
            }
            else
            {
                std::cout << "Failed to create directory: "
                        << dirName << std::endl;
            }
        }
    }


    else if (command.name == "touch")
    {
        if (command.args.empty())
        {
            std::cout << "Usage: touch <filename>"
                    << std::endl;

            return true;
        }

        for (const auto& fileName : command.args)
        {
            if (fs.createFile(fileName))
            {
                std::cout << "File created: "
                        << fileName << std::endl;
            }
            else
            {
                std::cout << "Failed to create file: "
                        << fileName << std::endl;
            }
        }
    }



    else if (command.name == "ls")
    {
        fs.list();
    }

    else if (command.name == "write")
    {
        if (command.args.size() < 2)
        {
            std::cout << "Usage: write <file> <content>"
                      << std::endl;

            return false;
        }

        std::string content;

        for (size_t i = 1; i < command.args.size(); i++)
        {
            content += command.args[i];

            if (i != command.args.size() - 1)
            {
                content += " ";
            }
        }

        if (fs.writeToFile(command.args[0], content))
        {
            std::cout << "Written successfully" << std::endl;
        }
        else
        {
            std::cout << "Write failed" << std::endl;
        }
    }

    else if (command.name == "cat")
    {
        if (command.args.size() != 1)
        {
            std::cout << "Usage: cat <filename>" << std::endl;

            return false;
        }

        fs.readFile(command.args[0]);
    }

    else if (command.name == "exit")
    {
        return false;
    }

    else
    {
        std::cout << "Unknown command" << std::endl;
    }

    return true;
}
