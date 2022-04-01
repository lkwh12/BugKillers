#pragma once

#include "ICommand.h"
#include "Input.h"

class CommandFactory {
public:
	shared_ptr<ICommand> createCommand(Input input);
};
