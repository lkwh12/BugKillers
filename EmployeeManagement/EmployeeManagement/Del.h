#pragma once

#include "ICommand.h"
#include "FilterConverter.h"
#include "Filter.h"
#include "Input.h"

using namespace std;

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
		// check Argument

		return false;
	}

	int deleteById(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

	int deleteByName(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

	int deleteByPhone(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

	int deleteByBirth(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

	int deleteByCl(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

	int deleteByCerti(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return result.size();
	}

private:
	Input input;
};
