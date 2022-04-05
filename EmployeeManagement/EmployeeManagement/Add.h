#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include "Constants.h"
#include <sstream>

enum class AddPayloadIndex {
	EMPLOYNUM,
	NAME,
	CL,
	PHONENUM,
	BIRTHDAY,
	CERTI,
};

class Add : public ICommand {
public:
	Add(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) override {
		bool ret = true;

		ret = checkException(input.getPayload());
		if (ret == false) return false;

		Employee e = makeEmployeeData(input.getPayload());
		ret = db.insert(e);

		return ret;
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
		// Check Employee No
		if (payloads[(int)AddPayloadIndex::EMPLOYNUM].empty() || payloads[(int)AddPayloadIndex::EMPLOYNUM].length() != LEN_EMP_NO) {
			//throw invalid_argument("ERROR:: invalid Employee No format!");
			return false;
		}

		// Check Name
		if (payloads[(int)AddPayloadIndex::NAME].empty() || payloads[(int)AddPayloadIndex::NAME].length() > LEN_EMP_NAME) {
			//throw invalid_argument("ERROR:: invalid Name format!");
			return false;
		}

		vector<string> names = split(payloads[(int)AddPayloadIndex::NAME], ' ');
		if (names.size() != CHUNK_CNT_NAME) {
			//throw invalid_argument("ERROR:: invalid Name format!");
			return false;
		}

		// Check Phone Number
		if (payloads[(int)AddPayloadIndex::PHONENUM].empty() || payloads[(int)AddPayloadIndex::PHONENUM].length() != LEN_EMP_PHONE_NUMBER) {
			//throw invalid_argument("ERROR:: invalid Phone Number format!");
			return false;
		}
		vector<string> phoneNums = split(payloads[(int)AddPayloadIndex::PHONENUM], '-');
		if (phoneNums.size() != CHUNK_CNT_PHONE_NUMBER) {
			//throw invalid_argument("ERROR:: invalid Phone Number format!");
			return false;
		}
		for (const auto& numbers : phoneNums) {
			for (const auto& num : numbers) {
				if (num > '9' || num < '0') {
					//throw invalid_argument("ERROR:: invalid Phone Number format!");
					return false;
				}
			}
		}

		// Check Birthday
		if (payloads[(int)AddPayloadIndex::BIRTHDAY].empty() || payloads[(int)AddPayloadIndex::BIRTHDAY].length() != LEN_EMP_BIRTHDAY) {
			//throw invalid_argument("ERROR:: invalid birthday format!");
			return false;
		}
		for (const auto& num : payloads[(int)AddPayloadIndex::BIRTHDAY]) {
			if (num > '9' || num < '0') {
				//throw invalid_argument("ERROR:: invalid birthday format!");
				return false;
			}
		}

		// Check CL
		if (payloads[(int)AddPayloadIndex::CL] != "CL1" && payloads[(int)AddPayloadIndex::CL] != "CL2" &&
			payloads[(int)AddPayloadIndex::CL] != "CL3" && payloads[(int)AddPayloadIndex::CL] != "CL4") {
			//throw invalid_argument("ERROR:: invalid CL format!");
			return false;
		}

		// Check Certi
		if (payloads[(int)AddPayloadIndex::CERTI] != "ADV" && payloads[(int)AddPayloadIndex::CERTI] != "PRO" && payloads[(int)AddPayloadIndex::CERTI] != "EX") {
			//throw invalid_argument("ERROR:: invalid Certi format!");
			return false;
		}
		return true;
	}

	Employee makeEmployeeData(const vector<string>& payloads) {
		auto names = split(payloads[(int)AddPayloadIndex::NAME], ' ');
		auto phoneNumbers = split(payloads[(int)AddPayloadIndex::PHONENUM], '-');

		return Employee(payloads[(int)AddPayloadIndex::EMPLOYNUM],
			Name(names[0], names[1]),
			PhoneNum(phoneNumbers[1], phoneNumbers[2]),
			BirthDay(payloads[(int)AddPayloadIndex::BIRTHDAY].substr(0, 4), payloads[(int)AddPayloadIndex::BIRTHDAY].substr(4, 2), payloads[(int)AddPayloadIndex::BIRTHDAY].substr(6, 2)),
			payloads[(int)AddPayloadIndex::CL], payloads[(int)AddPayloadIndex::CERTI]);
	}

private:
	Input input;
};
