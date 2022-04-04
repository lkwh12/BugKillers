#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"

using namespace std;

class Mod : public ICommand {
public:
	Mod(const Input& input) : input_(input) {

	}

	virtual bool execute(const IDatabase& db, const ILogger& logger) {
		return true;
	}

	bool doModify(vector<Employee>& searchResult) {
		return true;
	}
private:
	Input input_;
};
