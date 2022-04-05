#pragma once

#include "ICommand.h"
#include "FilterConverter.h"
#include "Input.h"

using namespace std;

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) override {
		auto result = db.query(getFilter());
	
		logger.dump(input.getCommand(), result);
		
		db.remove(getEmployeeNumList(result));

		return true;
	}

	int getDeleteResult(IDatabase& db)
	{
		int result = deleteByColumn(db);

		return result;
	}

private:
	Input input;
	FilterConverter filterConverter;

	Filter getFilter()
	{
		return filterConverter.getFilter(input);
	}

	vector<string> getEmployeeNumList(const vector<shared_ptr<Employee>>& eNum_list)
	{
		vector<string> result;
		result.reserve(eNum_list.size());

		for (const auto& it : eNum_list) {
			result.emplace_back(it->employeeNum_);
		}

		return result;
	}

	int deleteByColumn(IDatabase& db)
	{
		auto result = db.query(getFilter());

		db.remove(getEmployeeNumList(result));

		return (int)result.size();
	}
};
