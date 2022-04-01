#pragma once

#include "ICommand.h"
#include "Filter.h"


class Mod : public ICommand {
public:
	Mod() {}
	virtual void execute(const IDatabase& db, const ILogger& logger) {

	}
private:
};