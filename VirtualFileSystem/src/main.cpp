#include "../include/FileSystem.h"
#include "../include/CommandParser.h"
#include "../include/CommandHandler.h"

#include <iostream>

int main()
{
    FileSystem fs;

    CommandParser parser;

    CommandHandler handler;

    std::cout << "Virtual File System Started"
              << std::endl;

    while (true)
    {
        std::cout << "vfs> ";

        std::string input;

        std::getline(std::cin, input);

        ParsedCommand command = parser.parse(input);

        bool shouldContinue =
            handler.execute(command, fs);

        if (!shouldContinue)
        {
            break;
        }
    }

    return 0;
}
