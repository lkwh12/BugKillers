#pragma once

#include "ICommand.h"


class CommandFactory {
public:
	//ICommand* createCommand(string command);
	shared_ptr<ICommand> createCommand(string command);
};
