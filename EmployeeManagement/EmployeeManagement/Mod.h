#pragma once

#include "ICommand.h"
#include "Filter.h"


class Mod : public ICommand {
public:
	Mod() {}
	virtual bool execute(const IDatabase& db, const ILogger& logger) {
		return true;
	}
private:
};
