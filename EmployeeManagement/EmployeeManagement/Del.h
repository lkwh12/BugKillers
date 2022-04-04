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
		FilterConverter filterConverter;
		auto result = db.query(filterConverter.getFilter(input));
		logger.dump("DEL", result);
		vector<string> eNum;
		eNum.reserve(result.size());
		for (auto it : result) eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return true;
	}

	int deleteById(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

	int deleteByName(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

	int deleteByPhone(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

	int deleteByBirth(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

	int deleteByCl(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

	int deleteByCerti(IDatabase& db, Filter& filter)
	{
		auto result = db.query(filter);

		vector<string> eNum;
		for (auto it : result)
			eNum.emplace_back(it->employeeNum_);
		db.remove(eNum);

		return (int)result.size();
	}

private:
	Input input;
};
