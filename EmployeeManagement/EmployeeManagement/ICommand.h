#pragma once
#include "Interface.h"
#include "IDatabase.h"
#include "ILogger.h"

interface ICommand {
	virtual void execute(const IDatabase& db, const ILogger& logger) = 0;
};
