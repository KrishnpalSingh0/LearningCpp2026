#pragma once

#include "ParsedCommand.h"

class CommandParser
{
public:
    ParsedCommand parse(const std::string& input);
};
