#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "FilterConverter.h"
#include "Input.h"

class Sch : public ICommand {
public:
	Sch(const Input& input_) : input(input_) {}
	virtual vector<shared_ptr<Employee>> execute(IDatabase& db, ILogger& logger) override {
		FilterConverter filterConverter;

 		auto outputList =  db.query(filterConverter.getFilter(input));
		logger.dump(input.getCommand(), outputList);

		return outputList;
	}
private:
	Input input;
};
