#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "FilterConverter.h"
#include "Input.h"
#include "Constants.h"

class Sch : public ICommand {
public:
	Sch(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) override {
		FilterConverter filterConverter;
		bool ret = true;

		ret = checkException(input.getPayload());
		if (ret == false) return false;

		auto outputList = db.query(filterConverter.getFilter(input));
		logger.dump(input.getCommand(), outputList);

		return true;
	}

	vector<string> split(string str, char Delimiter) {
		istringstream iss(str);
		string buffer;
		vector<string> result;

		while (getline(iss, buffer, Delimiter)) {
			result.push_back(buffer);
		}

		return result;
	}

	bool checkException(const vector<string>& payloads) {

		if (payloads[0] == "employeeNum" && payloads[1].length() != LEN_EMP_NO) {
			return false;
		}

		if (payloads[0] == "name" && payloads[1].length() > LEN_EMP_NAME) {
			return false;
		}

		if (payloads[0] == "cl" &&
			(payloads[1] != "CL1" && payloads[1] != "CL2" && payloads[1] != "CL3" && payloads[1] != "CL4")) {
			return false;
		}

		if (payloads[0] == "phoneNum" &&
			(payloads[1].length() != LEN_EMP_PHONE_NUMBER &&
				payloads[1].length() != LEN_EMP_PHONE_NUMBER_MID &&
				payloads[1].length() != LEN_EMP_PHONE_NUMBER_LAST)) {
			return false;
		}

		if (payloads[0] == "birthday" &&
			(payloads[1].length() != LEN_EMP_BIRTHDAY_DAY &&
				payloads[1].length() != LEN_EMP_BIRTHDAY_YEAR &&
				payloads[1].length() != LEN_EMP_BIRTHDAY_MONTH &&
				payloads[1].length() != LEN_EMP_BIRTHDAY_DAY)) {
			return false;
		}

		if (payloads[0] == "certi" && (payloads[1] != "ADV" && payloads[1] != "PRO" && payloads[1] != "EX")) {
			return false;
		}
		return true;
	}

private:
	Input input;
};
