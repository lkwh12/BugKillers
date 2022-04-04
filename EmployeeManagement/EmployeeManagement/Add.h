#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"

class Add : public ICommand {
public:
	Add(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		return true;
	}
private:
	Input input;
};