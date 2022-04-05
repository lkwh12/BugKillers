#pragma once
#include "Interface.h"
#include "IDatabase.h"
#include "ILogger.h"

interface ICommand {
	virtual vector<shared_ptr<Employee>> execute(IDatabase& db, ILogger& logger) = 0;
};
