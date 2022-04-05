#pragma once

#include "ICommand.h"
#include "Filter.h"
#include "Input.h"
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
		if (payloads[(int)AddPayloadIndex::EMPLOYNUM].empty() || payloads[(int)AddPayloadIndex::EMPLOYNUM].length() != Employee::LEN_EMP_NO) {
			return false;
		}

		if (payloads[(int)AddPayloadIndex::NAME].empty() || payloads[(int)AddPayloadIndex::NAME].length() > Name::LEN_EMP_NAME) {
			return false;
		}

		vector<string> names = split(payloads[(int)AddPayloadIndex::NAME], ' ');
		if (names.size() != Name::CHUNK_CNT_NAME) {
			return false;
		}

		if (payloads[(int)AddPayloadIndex::PHONENUM].empty() || payloads[(int)AddPayloadIndex::PHONENUM].length() != PhoneNum::LEN_EMP_PHONE_NUMBER) {
			return false;
		}
		vector<string> phoneNums = split(payloads[(int)AddPayloadIndex::PHONENUM], '-');
		if (phoneNums.size() != PhoneNum::CHUNK_CNT_PHONE_NUMBER) {
			return false;
		}
		for (const auto& numbers : phoneNums) {
			for (const auto& num : numbers) {
				if (num > '9' || num < '0') {
					return false;
				}
			}
		}

		if (payloads[(int)AddPayloadIndex::BIRTHDAY].empty() || payloads[(int)AddPayloadIndex::BIRTHDAY].length() != BirthDay::LEN_EMP_BIRTHDAY) {
			return false;
		}
		for (const auto& num : payloads[(int)AddPayloadIndex::BIRTHDAY]) {
			if (num > '9' || num < '0') {
				return false;
			}
		}

		if (payloads[(int)AddPayloadIndex::CL] != "CL1" && payloads[(int)AddPayloadIndex::CL] != "CL2" &&
			payloads[(int)AddPayloadIndex::CL] != "CL3" && payloads[(int)AddPayloadIndex::CL] != "CL4") {
			return false;
		}

		if (payloads[(int)AddPayloadIndex::CERTI] != "ADV" && payloads[(int)AddPayloadIndex::CERTI] != "PRO" && payloads[(int)AddPayloadIndex::CERTI] != "EX") {
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
