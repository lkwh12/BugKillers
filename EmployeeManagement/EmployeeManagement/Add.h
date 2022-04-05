#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
#include <sstream>

enum Format {
	LengthEmpNo = 8,
	ChunkCountName = 2,
	LengthName = 15,
	ChunkCountPhoneNum = 3,
	LengthPhoneNum = 13,
	LengthBirthday = 8
};

class Add : public ICommand {
public:
	Add(const Input& input_) : input(input_) {}
	virtual bool execute(IDatabase& db, ILogger& logger) {
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
		if (payloads[0].empty() || payloads[0].length() != LengthEmpNo) {
			//throw invalid_argument("ERROR:: invalid Employee No format!");
			return false;
		}

		// Check Name
		if (payloads[1].empty() || payloads[1].length() > LengthName) {
			//throw invalid_argument("ERROR:: invalid Name format!");
			return false;
		}

		vector<string> names = split(payloads[1], ' ');
		if (names.size() != ChunkCountName) {
			//throw invalid_argument("ERROR:: invalid Name format!");
			return false;
		}

		// Check Phone Number
		if (payloads[3].empty() || payloads[3].length() != LengthPhoneNum) {
			//throw invalid_argument("ERROR:: invalid Phone Number format!");
			return false;
		}
		vector<string> phoneNums = split(payloads[3], '-');
		if (phoneNums.size() != ChunkCountPhoneNum) {
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
		if (payloads[4].empty() || payloads[4].length() != LengthBirthday) {
			//throw invalid_argument("ERROR:: invalid birthday format!");
			return false;
		}
		for (const auto& num : payloads[4]) {
			if (num > '9' || num < '0') {
				//throw invalid_argument("ERROR:: invalid birthday format!");
				return false;
			}
		}

		// Check CL
		if (payloads[2] != "CL1" && payloads[2] != "CL2" &&
			payloads[2] != "CL3" && payloads[2] != "CL4") {
			//throw invalid_argument("ERROR:: invalid CL format!");
			return false;
		}

		// Check Certi
		if (payloads[5] != "ADV" && payloads[5] != "PRO" && payloads[5] != "EX") {
			//throw invalid_argument("ERROR:: invalid Certi format!");
			return false;
		}
		return true;
	}

	Employee makeEmployeeData(const vector<string>& payloads) {
		auto names = split(payloads[1], ' ');
		auto phoneNumbers = split(payloads[3], '-');

		return Employee(payloads[0],
			Name(names[0], names[1]),
			PhoneNum(phoneNumbers[1], phoneNumbers[2]),
			BirthDay(payloads[4].substr(0, 4), payloads[4].substr(4, 2), payloads[4].substr(6, 2)),
			payloads[2], payloads[5]);
	}

private:
	Input input;
};
