#pragma once
#include "Interface.h"
#include "IDatabase.h"
#include "ILogger.h"

interface ICommand {
	virtual bool execute(const IDatabase& db, const ILogger& logger) = 0;
};
