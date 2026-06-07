#include "../include/CommandParser.h"

#include <sstream>

ParsedCommand CommandParser::parse(const std::string& input)
{
    ParsedCommand command;

    std::stringstream ss(input);

    ss >> command.name;

    std::string arg;

    while (ss >> arg)
    {
        command.args.push_back(arg);
    }

    return command;
}
