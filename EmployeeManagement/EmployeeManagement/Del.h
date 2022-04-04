#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(const IDatabase& db, const ILogger& logger)	{
		return true;
	}

private:
	Input input;
};
