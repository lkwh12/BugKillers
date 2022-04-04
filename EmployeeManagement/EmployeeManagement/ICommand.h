#pragma once
#include "Interface.h"
#include "IDatabase.h"
#include "ILogger.h"

interface ICommand {
	virtual bool execute(IDatabase& db, ILogger& logger) = 0;
};
