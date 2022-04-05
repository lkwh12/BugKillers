#pragma once

#include "ICommand.h"
#include "FilterConverter.h"
#include "Input.h"

class Del : public ICommand {
public:
	Del(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) override {
		if (!checkException()) {
			return false;
		}
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

	bool checkException()
	{
		const vector<string>& payloads = input.getPayload();

		if (payloads[0] == "employeeNum" && payloads[1].length() != Employee::LEN_EMP_NO) {
			return false;
		}
		else if (payloads[0] == "name" && payloads[1].length() > Name::LEN_EMP_NAME) {
			return false;
		}
		else if (payloads[0] == "cl" &&
			(payloads[1] != "CL1" && payloads[1] != "CL2" && payloads[1] != "CL3" && payloads[1] != "CL4")) {
			return false;
		}
		else if (payloads[0] == "phoneNum" && payloads[1].length() != PhoneNum::LEN_EMP_PHONE_NUMBER) {
			return false;
		}
		else if (payloads[0] == "birthday" && payloads[1].length() != BirthDay::LEN_EMP_BIRTHDAY) {
			return false;
		}
		else if (payloads[0] == "certi" &&
			(payloads[1] != "ADV" && payloads[1] != "PRO" && payloads[1] != "EX")) {
			return false;
		}
		return true;
	}

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
