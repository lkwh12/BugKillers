#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include "FilterConverter.h"

using namespace std;

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		FilterConverter filterConverter;

		auto outputList = db.query(filterConverter.getFilter(input));
		logger.dump("DEL", outputList);
		vector<string> employeeNums;
		employeeNums.reserve(outputList.size());
		for (auto e : outputList) employeeNums.emplace_back(e->employeeNum_);

		db.remove(employeeNums);
		return true;
	}
private:
	Input input;
};
