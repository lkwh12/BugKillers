#pragma once

#include "ICommand.h"
#include "Input.h"
#include "Add.h"
#include "Sch.h"
#include "Del.h"
#include "Mod.h"
#include <memory>

class CommandFactory {
public:
	shared_ptr<ICommand> createCommand(Input input);
};
