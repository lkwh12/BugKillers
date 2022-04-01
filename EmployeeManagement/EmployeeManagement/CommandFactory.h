#pragma once

#include "ICommand.h"

class CommandFactory {
public:
	shared_ptr<ICommand> createCommand(string command);
};
