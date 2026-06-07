#pragma once

#include "ParsedCommand.h"
#include "FileSystem.h"

class CommandHandler
{
public:
    bool execute(const ParsedCommand& command,
                 FileSystem& fs);
};
